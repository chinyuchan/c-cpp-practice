#include <iostream>
using namespace std;

class A {
public:
    virtual void foo1() { cout << "A::foo1()" << endl; }
    virtual void foo2() { cout << "A::foo2()" << endl; }
};

class B {
public:
    virtual void bar1() { cout << "B::bar1()" << endl; }
    virtual void bar2() { cout << "B::bar2()" << endl; }
};

class C : public A, public B {
public:
    void foo1() override {
        cout << "C::foo1()" << endl;
    }
    void bar1() override {
        cout << "C::bar1()" << endl;
    }
    virtual void call1() {
        cout << "C::call1()" << endl;
    }
    virtual void call2() {
        cout << "C::call2()" << endl;
    }
};

int main() {
    cout << sizeof(C) << endl; // 16

    C c;
    void(***fp)();
    fp = reinterpret_cast<void(***)()>(&c);
    (*fp)[0]();
    (*fp)[1]();
    (*fp)[2]();
    (*fp)[3]();
    (*fp)[4]();

    cout << "----------------------------------------" << endl;

    fp = reinterpret_cast<void(***)()>((char*)&c+8);
    (*fp)[0]();
    (*fp)[1]();



    return 0;
}
