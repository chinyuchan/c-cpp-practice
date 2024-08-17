#include <iostream>
using namespace std;

class A {
public:
    int x;
};

class B : A {

};

struct C {
    int x;
};

struct D : C {};

int main()
{
    B b;
    // b.x;

    D d;
    cout << d.x << endl;

    return 0;
}
