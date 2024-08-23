#include <iostream>
using namespace std;

class Father {};
class Son: public Father {};
Father f;
Son s;

class A {
public:
    virtual int f1() {
        cout << "A::f1()" << endl;
        return 1;
    }

    virtual int* f2() {
        cout << "A::f2()" << endl;
        return nullptr;
    }

    virtual Father f3() {
        cout << "A::f3()" << endl;
        return Father{};
    }

    virtual Father& f4() {
        cout << "A::f4()" << endl;
        return f;
    }

    virtual Father* f5() {
        cout << "A::f5()" << endl;
        return &f;
    }

    virtual void f6() throw(int,string,Father) {
        cout << "A::f6()" << endl;
    }

    virtual void f7() {
        cout << "A::f7()" << endl;
    }
    void call(A* pa) { pa->f8(); }
    void call2(A& ra) { ra.f8(); }
private:
    virtual void f8() {
        cout << "A::f8()" << endl;
    }
};


class B : public A {
public:
    int f1() override {
        cout << "B::f1()" << endl;
        return 1;
    }
    int* f2() override {
        cout << "B::f2()" << endl;
        return nullptr;
    }

    // Compile ERROR
    // Son f3() override {
    //     cout << "B::f3()" << endl;
    //     return Son{};
    // }

    Son& f4() override {
        cout << "B::f4()" << endl;
        return s;
    }

    Son* f5() override {
        cout << "B::f5()" << endl;
        return &s;
    }

    void f6() throw(int,string,Son) override  {
        cout << "B::f6()" << endl;
    }

    void f8() override {
        cout << "B::f8()" << endl;
    }


private:
    // 子类重写的虚函数，访问控制属性不会影响多态
    void f7() override {
        cout << "B::f7()" << endl;
    }
};


int main()
{
    B b;
    A* pa = &b;
    pa->f1();
    pa->f2();
    pa->f4();
    pa->f5();
    pa->f6();
    pa->f7();
    pa->call(&b);
    pa->call2(b);
    return 0;
}
