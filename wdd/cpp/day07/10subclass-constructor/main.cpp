#include <iostream>
using namespace std;

class X {
public:
    explicit X(int m = 0, int n = 0) : _m(m), _n(n) {}
private:
    int _m;
    int _n;
};

class Y {
public:
    explicit Y(int data) : _data(data) {}
    void show() const { cout << _data << endl; }
private:
    int _data;
};

class S : public X {
public:
    // 如果父类没有无参构造的解决方法：
    // 1.给父类加一个无参构造函数
    // 2.让父类的有参构造带默认值
    S(): _y(1), _a(2), _b(3) {}
    explicit S(int m) : X(m), _y(1), _a(2), _b(3) {}
    explicit S(int m, int n) : X(m, n), _y(1), _a(2), _b(3) {}
    void show() const {
        cout << _a << ' ' << _b << endl;
        _y.show();
    }
private:
    Y _y;
    int _a;
    int _b;
};


int main() {
    S s;
    s.show();

    return 0;
}
