#include <iostream>
using namespace std;

class Father {
public:
    void show()const { cout << x << ' ' << y << ' ' << z << endl; }
    int x;
protected:
    int y;
private:
    int z;
};

class Son : private Father {
public:
    void foo() {
        cout << x << endl;
        cout << y << endl;
        // cout << z << endl;
        show();
    }
};

class X : private Son {
public:
    void bar() {
        // cout << x << endl;

    }
};

int main()
{
    Son s;
    // cout << s.x << endl;
    // cout << s.y << endl;
    // cout << s.z << endl;

    return 0;
}
