#include <iostream>
using namespace std;

class X {
public:
    X() {
        cout << "X()" << endl;
    }
};

class Y {
public:
    Y() {
        cout << "Y()" << endl;
    }
};

class Z {
public:
    Z() {
        cout << "Z()" << endl;
    }
};

class S : public X, public Z, public Y {
public:
    // 如果没有指明父类的构造方式，就会默认调用父类的无参构造函数
    // 如果父类没有无参构造函数，则会报错
    S() {}
    explicit S(int data) : _data(data) {}
private:
    int _data;
};


int main() {
    S s1;
    cout << "----------------------" << endl;
    S s2(100);

    return 0;
}
