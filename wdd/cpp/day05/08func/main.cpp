#include <iostream>
using namespace std;

class Square {
public:
    explicit Square(int x = 0) : x(x) {}

    Square& operator()() {
        x = x*x;
        return *this;
    }

    Square& operator()(int n) {
        x += n;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Square& s) {
        return os << s.x;
    }

private:
    int x;
};

int main() {
    Square s(10);
    s()()();
    cout << s << endl;
    s(1)(2)(3)(4);
    cout << s << endl;
    Square s1(10);

    s1(2)();
    cout << s1 << endl;

    return 0;
}


