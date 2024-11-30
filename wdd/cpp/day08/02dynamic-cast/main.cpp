#include <iostream>
using namespace std;

class A {
public:
    explicit A(int a) : _a(a) {}
    virtual void func() {
        cout << "A::func()" << endl;
    }
private:
    int _a;
};

class B : public A {
public:
    explicit B(int b) : A(b), _b(b) {}
    void func() override {
        cout << "B::func()" << endl;
    }
private:
    int  _b;
};

class C : public A {
public:
    explicit C(int c) : A(c), _c(c) {}
    void func() override {
        cout << "C::func()" << endl;
    }
private:
    double _c;
};

int main()
{
    A* pa = new B(100);
    B* pb = dynamic_cast<B*>(pa);
    cout << "pb = " << pb << endl;

    C* pc = new C(200);
    pb = dynamic_cast<B*>(pc);
    cout << "pb = " << pb << endl; // 转换失败，pb为0

    delete pa;
    delete pc;

    B b(1);
    A& ra = b;
    try {
        C& rc = dynamic_cast<C&>(ra);
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }


    return 0;
}
