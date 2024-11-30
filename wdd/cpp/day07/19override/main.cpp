#include <iostream>
using namespace std;

class A {
public:
    void f1() { cout<<"A::f1()" << endl; }
    virtual void f2() { cout << "A::f2()" << endl; }
    virtual void f3() { cout << "A::f3()" << endl; }
    virtual void f4(int x) { cout << "A::f4(int)" << endl; }
    virtual void f5(int& x) { cout << "A::f5(int&)" << endl; }
    virtual void f6(int* x) { cout << "A::f6(int&)" << endl; }
    virtual void f7(int& x) { cout << "A::f7(int&)" << endl; }
    virtual void f7(const int& x) { cout << "A::f7(const int&)" << endl; }
    virtual void f8(int* x) { cout << "A::f8(int*)" << endl; }
    virtual void f8(const int* x) { cout << "A::f8(const int*)" << endl; }
    virtual void f9() const { cout << "A::f9()const" << endl; }
    virtual void f10() { cout << "A::f10()" << endl; }
};

class B : public A {
public:
    // 隐藏父类的f1
    void f1() { cout<<"B::f1()" << endl; }
    void f2() override { cout << "B::f2()" << endl; }
    void f3(int x) { cout << "B::f3(int)" << endl; }
    // 构成重写，对于普通数据类型，有无常属性不影响
    void f4(const int x) override { cout << "B::f4(const int)" << endl; }
    // 不构成重写，常属性不一致
    void f5(const int& x) { cout << "B::f5(const int&)" << endl; }
    // 不构成重写，常属性不一致
    void f6(const int* x) { cout << "B::f6(const int*)" << endl; }
    void f7(int& x) override { cout << "B::f7(int&)" << endl; }
    void f7(const int& x) override { cout << "B::f7(const int&)" << endl; }
    void f8(int* x) override { cout << "B::f8(int*)" << endl; }
    void f8(const int* x) override { cout << "B::f8(const int*)" << endl; }
    void f9() { cout << "B::f9()" << endl; }
    void f10() const { cout << "B::f10()const" << endl; }
};

int main()
{
    B b;
    A* pa = &b;
    pa->f1();
    pa->f2();
    pa->f3();
    int a = 1024;
    pa->f4(a);
    pa->f5(a);
    pa->f6(&a);
    pa->f7(a);
    pa->f8(&a);
    const int* pb = &a;
    pa->f8(pb);
    pa->f9();
    pa->f10();
    return 0;
}
