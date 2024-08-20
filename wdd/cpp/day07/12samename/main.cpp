#include <iostream>
using namespace std;

int a = 1234;

void foo() {
    cout << "::foo()" << endl;
}

class A {
public:
    explicit A(int a=1024) : a(a) {}

    void foo() {
        cout << "A::foo()" << endl;
    }

    void set_a(int a) {
        cout << "全局变量：" << ::a << endl;
        cout << "局部变量：" << a << endl;
        cout << "成员变量：" << this->a << endl;
        this->a = a;

        foo();

        ::foo();
    }

    int a;
};

class B : public A {
public:
    explicit B(int a = 9527) : a(a) {}
    void set_a(int a) {
        cout << "全局变量：" << ::a << endl;
        cout << "局部变量：" << a << endl;
        cout << "成员变量（父类）：" << A::a << endl;
        cout << "成员变量（自己）：" << this->a << endl;
    }
    int a;
};

int main() {
    A a;
    a.set_a(10);
    cout << "--------------------------------" << endl;
    B b;
    cout << b.a << endl;
    cout << b.A::a << endl;
    b.set_a(100);
    cout << "--------------------------------" << endl;
    b.A::set_a(200);

    return 0;
}
