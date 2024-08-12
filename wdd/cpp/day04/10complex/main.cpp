#include <iostream>
using namespace std;

class Complex {
public:
    explicit Complex(int r=0, int v=0) : r(r), v(v) {}

    Complex operator+(const Complex& rhs) const {
        return Complex(r + rhs.r, v + rhs.v);
    }

    Complex operator-(const Complex& rhs) const {
        return Complex(r - rhs.r, v - rhs.v);
    }

    friend ostream& operator<<(ostream& os, const Complex& rhs);

    // rhs不能加const，因为向其写入本身就是要改变
    friend istream& operator>>(istream& is, Complex& rhs) {
        return is >> rhs.r >> rhs.v;
    }
private:
    int r;
    int v;
};

// 返回引用是为了支持连续输出
ostream& operator<<(ostream& os, const Complex& rhs) {
    return os << '(' << rhs.r << ',' << rhs.v << "i)";
}

int main()
{
    Complex c1(1,2), c2(3,4);
    Complex c3 = c1 + c2;
    // 需要在cout类里面实现成员函数，因此只能用全局方式重载
    cout << c3 << endl; // cout.operator<<(c3);
    Complex c4 = c1 - c2;
    cout << c4 << endl;

    Complex c5;
    cin >> c5;
    cout << c5 << endl;

    return 0;
}
