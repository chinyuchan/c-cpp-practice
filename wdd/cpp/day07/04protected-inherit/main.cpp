#include <iostream>
using namespace std;

class Father {
public:
    int x;
protected:
    int y;
private:
    int z;
};

class Son : protected Father {
public:
    void foo() const {
        cout << x << endl;
        cout << y << endl;
        // cout << z << endl;
    }
};

class X : private Son {
public:
    void bar() const {
        cout << x << endl;
        cout << y << endl;
        // cout << z << endl;
    }
};

int main()
{
    Father f;
    Son s;
    //cout << s.x << endl;

    return 0;
}
