#include <iostream>

using namespace std;

class A {
public:
    virtual void foo() const throw() {
        cout << "A::foo()" << endl;
    }
    virtual void bar() const throw(bad_alloc, bad_cast, out_of_range) {
        cout << "A::baroo()" << endl;
    }
    virtual void func() const throw(bad_alloc) {
        cout << "A::func()" << endl;
    }
    virtual void good() const throw(exception) {
        cout << "A::good()" << endl;
    }
    virtual void hello() const noexcept {
        cout << "A::hello()" << endl;
    }
    virtual void world() const noexcept(false) {
        cout << "A::world()" << endl;
    }
    virtual void hey() const noexcept(false) {
        cout << "A::hey()" << endl;
    }
};

class B : public A {
public:
    // 重写时异常说明也要一致
    void foo() const throw() override {
        cout << "B::foo()" << endl;
    }

    // 异常说明的类型可以比基类的少，但是不能比基类的多
    void bar() const throw(bad_alloc, bad_cast) override {
        cout << "B::bar()" << endl;
    }

    // 编译错误
    // 不能比基类的异常的类型说明多
    // void func() const throw(bad_alloc, bad_cast) override {}

    // 子类抛出的类型都可以隐式转成exception类型，因此这种写法是可以的
    // 即子类只抛出了一种类型
    void good() const throw(bad_alloc, bad_cast, out_of_range) override {
        cout << "B::good()" << endl;
    }

    void hello() const noexcept override {
        cout << "B::hello()" << endl;
    }
    void world() const noexcept(false) override {
        cout << "B::world()" << endl;
    }
    // 基类抛出异常，子类可以不抛出异常
    // 即子类抛出的异常类型可以比基类的少
    void hey() const noexcept(true) override {
        cout << "B::hey()" << endl;
    }
};


int main()
{

    return 0;
}
