#include <iostream>
using namespace std;

class A {
public:
    void show() const {
        cout << _x << ' ' << _y << endl;
    }
    int _x;
    int _y;
};

//继承
class B : public  A {

};

// 组合
class C {
public:
    A _a;
};

int main() {
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;

    B b;
    cout << b._x << ' ' << b._y << endl;
    b.show();

    C c;
    cout << c._a._x << ' ' << c._a._y << endl;
    c._a.show();

    return 0;
}
