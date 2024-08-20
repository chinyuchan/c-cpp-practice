#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A()" << endl; }
    A(const A& a) { cout << "A(const A&)" << endl; }
    // A(const A& a) = default;
    ~A() { cout << "~A()"  << endl; }
    A& operator=(const A& a) {
        cout << "A& operator=(const A&)" << endl;
        // ...
        return *this;
    }
    // A& operator=(const A& a) = default;
};

class B : public A {
public:
    B() { cout << "B()" << endl; }
    B(const B& b) : A(b) { cout << "B(const B&)" << endl; }
    // B(const B& b) = default;
    ~B() { cout << "~B()"  << endl; }
    B& operator=(const B& b) {
        cout << "B& operator=(const B&)" << endl;
        A::operator=(b);
        // ...
        return *this;
    }
    // B& operator=(const B& b) = default;
};

class C {
public:
    C() { cout << "C()" << endl; }
    C(const C& c) { cout << "C(const C&)" << endl; }
    ~C() { cout << "~C()"  << endl; }
    C& operator=(const C& c) {
        cout << "C& operator=(const C&)" << endl;
        // ...
        return *this;
    }
};

class D {
public:
    D() { cout << "D()" << endl; }
    D(const D& d) { cout << "D(const D&)" << endl; }
    ~D() { cout << "~D()"  << endl; }
    D& operator=(const D& d) {
        cout << "D& operator=(const D&)" << endl;
        // ...
        return *this;
    }
};

class E {
public:
    E() { cout << "E()" << endl; }
    E(const E& e) { cout << "E(const E&)" << endl; }
    ~E() { cout << "~E()"  << endl; }
    E& operator=(const E& e) {
        cout << "E& operator=(const E&)" << endl;
        // ...
        return *this;
    }
};

class S : public C, public B {
public:
    S() { cout << "S()" << endl; }

    // 这种写法是默认调用各个父类的无参构造函数函数
    // S(const S&) { cout << "S(const S&) << endl"; }

    // 编译器生成的缺省拷贝构造函数是如下形式，会调用父类的构造函数
    // S(const S& s) : C(s), B(s), _d(s._d), _e(s._e) {
    //     cout << "S(const S&)" << endl;
    // }

    // C++11默认拷贝构造函数的写法
    S(const S& s) = default;

    // 这种写法不会处理基类部分
    // S& operator=(const S& s) {
    //     cout << "S& operator=(const S&)" << endl;
    //     return *this;
    // }

    // 编译器生成的缺省拷贝赋值函数是如下形式，会调用父类和类成员的构造函数
    // S& operator=(const S& s) {
    //     cout << "S& operator=(const S&)" << endl;
    //     // static_cast<C*>(this)->operator=(s);
    //     // static_cast<B*>(this)->operator=(s);
    //     // static_cast<B&>(*this) = (const B&)(s);
    //     // static_cast<C&>(*this) = (const C&)(s);
    //     C::operator=(s);
    //     B::operator=(s);
    //     _d.operator=(s._d); // _d = s._d;
    //     _e.operator=(s._e); // _e = s._e;
    //     // ...
    //     return *this;
    // }

    // C++11默认拷贝赋值函数的写法
    S& operator=(const S& s) = default;


    ~S() { cout << "~S()" << endl; }

private:
    D _d;
    E _e;
};

int main() {
    S s1;
    cout << "------------------------" << endl;
    {
        S s2(s1);
        cout << "------------------------" << endl;
        s2 = s1;
        cout << "------------------------" << endl;
    }
    cout << "------------------------" << endl;

    return 0;
}
