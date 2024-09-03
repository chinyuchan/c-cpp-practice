#include <iostream>
using namespace std;

class Interface {
public:
    explicit Interface(int x=0, int y=0) : _x(x), _y(y) {}
    virtual ~Interface() = default;
    virtual void foo() = 0;
    virtual void bar() = 0;
private:
    int _x;
    int _y;
};

class Derived : public Interface {
public:
    void foo() override {
        cout << "Derived::foo" << endl;
    }
    void bar() override {
        cout << "Derived::bar" << endl;
    }
};


int main()
{
    // 纯虚类不能实例化
    // Interface it;

    Derived bar;


    return 0;
}
