#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "A()" << endl;
    }
    ~A() {
        cout << "~A()" << endl;
    }
};

void run() {
    A a; // 能够析构
    A* pa = new A(); // 无法释放

    throw int(100);
}

int main()
{
    try {
        run();
    }
    catch (int e) {
        cout << "Exception: " << e << endl;
    }

    cout << "after try-catch" << endl;

    return 0;
}
