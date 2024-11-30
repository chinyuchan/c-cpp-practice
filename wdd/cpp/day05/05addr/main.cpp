#include <iostream>
using namespace std;

class A {
public:
    A(int x=0) : x(x) {}
    A* operator&() {
        cout << "operator&()" << endl;
        return this;
    }
    const A* operator&() const {
        cout << "operator&()const" << endl;
        return this;
    }
private:
    int x;
};

int main()
{
    A a(100);
    cout << &a << endl;
    const A b(200);
    cout << &b << endl;

    return 0;
}
