#include <iostream>
using namespace std;


class A {
public:
    A(int x = 0, int y = 0) : _x(x), _y(y) { cout << "A(int,int)" << endl; }
    ~A() { cout << "~A()" << endl; }
    void show() const { cout << _x << ' ' << _y << endl; }
private:
    int _x;
    int _y;
};

class B : public A {
public:
    B(int x = 0, int y = 0, int z = 0) : A(x, y), _z(z) { cout << "B(int,int,int)" << endl; }
    ~B() { cout << "~B()" << endl; }
    void foo() const { cout << _z << endl; }
private:
    int _z;
};

int main() {
    B b(1314, 9527, 1024);
    b.show();
    b.foo();

    A* pa = &b;
    pa->show();
    // pa->foo();

    A& ra = b;
    ra.show();
    // ra.foo();

    cout << "----------------------" << endl;
    pa = new B{1,2,3};
    //delete pa; // 只会调用父类的析构
    delete static_cast<B*>(pa);
    cout << "----------------------" << endl;

    return 0;
}
