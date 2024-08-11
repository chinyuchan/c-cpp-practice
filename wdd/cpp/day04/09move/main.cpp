#include <iostream>
using namespace std;

class A {
public:
    A(int a) {
        cout << "A(int)" << endl;
    }

    A(const A& a) {
        cout << "A(const A&)" << endl;
    }

    //移动构造函数
    A(A&& a) {
        cout << "A(&&)" << endl;
    }

    A& operator=(const A& a) {
        cout << "A& operator=(const A&)" << endl;
        return *this;
    }

    // 移动赋值函数
    A& operator=(A&& a) noexcept {
        cout << "A& operator=(A&&)" << endl;
        return *this;
    }

    ~A() {
        cout << "~A()" << endl;
    }
};

A getA() {
    A a(10);
    return a;
}

int main()
{
    A obj(A(10)); // 没有调用拷贝构造，被编译器优化了
    cout << "-----------------------" << endl;
    A obj1(move(obj));
    cout << "-----------------------" << endl;
    obj1 = getA();
    cout << "-----------------------" << endl;
    A obj2 = getA(); // 没有移动赋值、拷贝赋值，被编译器优化了
    cout << "-----------------------" << endl;


    return 0;
}
