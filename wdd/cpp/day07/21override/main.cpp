#include <iostream>
using namespace std;

class A {
public:
    void func() {
        cout << "A::func()" << endl;
    }
};

class B : public A {
public:
    // 隐藏
    void func(int x) {
        cout << "B::func(int)" << endl;
    }
};

class C : public B {
public:

};

int main()
{
    B b;
    // b.func();
    b.A::func();
    b.func(10);
    C c;

    return 0;
}
