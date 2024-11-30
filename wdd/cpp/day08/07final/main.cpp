#include <iostream>
using namespace std;


class Base final {};

// 编译报错
// class Derived : public Base {};

class A {
public:
    virtual void foo() final {
        cout << "A::foo()" << endl;
    }
    virtual void bar() {
        cout << "A::bar()" << endl;
    }
};

class B : public A {
public:
    // 编译报错
    // void foo() override {}

    void bar() override final {
        cout << "B::bar()" << endl;
    }
};

class C : public B {
public:
    // 编译报错
    // void bar() override {}
};


int main()
{
    C c;
    c.foo();
    c.bar();

    cout << "Base is final: " << boolalpha << is_final_v<Base> << endl;
    cout << "A is final: " << boolalpha << is_final_v<A> << endl;

    return 0;
}
