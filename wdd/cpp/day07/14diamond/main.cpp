#include <iostream>
using namespace std;

class A {
public:
    explicit A(int a = 1024) : a(a) {}
    int a;
};

class B : public A {
public:
    void set_a(int a) {
        cout << &this->a << endl;
        this->a = a;
    }
};

class C : public A {
public:
    int get_a() const {
        cout << &a << endl;
        return this->a;
    }
};


class D : public B, public C {

};

int main() {
    cout << sizeof(D) << endl;
    D d;
    cout << &d.B::a  << " " << d.B::a << endl;
    cout << &d.C::a  << " " << d.C::a << endl;
    d.set_a(1314);
    cout << d.get_a() << endl;
    return 0;
}
