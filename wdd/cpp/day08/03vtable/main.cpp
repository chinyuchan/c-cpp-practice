#include <iostream>
using namespace std;

class A {};

class B {
public:
    void func() {}
};

class C {
public:
    // 普通函数不会放到虚函数表中
    void hello() {
        cout << "C::hello" << endl;
    }
    virtual void func() {
        cout << "C::func()" << endl;
    }
    virtual void foo() {
        cout << "C::foo()" << endl;
    }
    virtual void bar() {
        cout << "C::bar()" << endl;
    }
};

int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    C c1,c2;
    cout << *(void**)&c1 << endl;
    cout << *(void**)&c2 << endl;

    void* p = *(void**)&c1;
    void(*pf)()  = reinterpret_cast<void(*)()>(*(void**)p);
    pf();
    cout << "sizeof(void) = " << sizeof(void) << endl;
    pf = reinterpret_cast<void(*)()>(*(void**)(p+8));
    pf();
    pf = reinterpret_cast<void(*)()>(*(void**)(p+16));
    pf();

    cout << "------------------------------------" << endl;
    // 函数指针数组的指针
    void(***fp)() = reinterpret_cast<void(***)()>(&c2);
    (*fp)[0]();
    (*fp)[1]();
    (*fp)[2]();
    return 0;
}
