#include <iostream>
using namespace std;


class A {
public:
    A(int x = 0, int y = 0) : _x(x), _y(y) { cout << "A(int,int)" << endl; }
    virtual ~A() { cout << "~A()" << endl; }
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
    A* pa = new B{1,2,3};
    delete pa;

    return 0;
}

