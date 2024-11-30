#include <iostream>
using namespace std;

class Boolean {
public:
    explicit Boolean(int n = 0) : n(n) {}
    explicit Boolean(bool b = false): n(b) {}
    Boolean operator&&(const Boolean& b) const { return Boolean(n && b.n); }
    Boolean operator||(const Boolean& b) const { return Boolean(n || b.n); }
    Boolean operator!() const { return Boolean(!n); }

    // convert from Boolean to bool
    explicit operator bool() const { return n; }

    friend ostream& operator<<(ostream& os, const Boolean& b) { return os << (b.n != 0 ? "true" : "false"); }

private:
    int n;
};

int main()
{
    Boolean b1(false), b2(1);
    cout << b1 << endl;
    Boolean b3 = Boolean(b1 && b2);
    cout << b3 << endl;
    cout << (b1 || b2) << endl;
    if (!b1) {
        cout << "b1 is false" << endl;
    }
    if (b2) {
        cout << "b2 is true" << endl;
    }
    return 0;
}
