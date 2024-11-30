#include <iostream>
using namespace std;

class Integer {
public:
    explicit Integer(int num=0) : num(num) {}
    Integer operator+(const Integer& i) const { return Integer(num + i.num); }
    friend Integer operator-(const Integer&, const Integer&);
    friend ostream& operator<<(ostream& os, const Integer& i) { return os << i.num; }
    Integer operator*(const Integer& i) const { return Integer(num * i.num); }
    Integer operator/(const Integer& i) const { return Integer(num / i.num); }
    Integer operator%(const Integer& i) const { return Integer(num % i.num); }

    Integer& operator++() {
        ++num;
        return *this;
    }

    Integer operator++(int) {
        int old = num;
        ++num;
        return Integer(old);
    }

    friend Integer& operator--(Integer&);
    friend Integer operator--(Integer&, int);
private:
    int num;
};

Integer operator-(const Integer& a, const Integer& b) { return Integer(a.num - b.num); }

Integer& operator--(Integer& i) {
    --i.num;
    return i;
}

Integer operator--(Integer& i, int) {
    int old = i.num;
    --i.num;
    return Integer(old);
}

int main()
{
    Integer a(10), b(20);
    Integer res = a + b; // a.operator+(b)
    cout << res << endl;
    res = a - b; // ::operator-(a, b)
    cout << res << endl;

    Integer c(10);
    cout << ++++++c << endl; // 13
    cout << c++ << endl; // 13
    cout << c << endl; // 14
    cout << ------c << endl; // 11
    cout << c-- << endl; // 11
    cout << c << endl; // 10

    return 0;
}
