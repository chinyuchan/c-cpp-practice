#include <iostream>
using namespace std;

class B {
public:
    explicit B(int y = 0) : _y(y) {}
    [[nodiscard]] int y() const { return _y; }
private:
    int _y;
};

class A {
public:
    explicit A(int x=0): _x(x) {}

    // 在A类中添加B类的单参构造
    explicit A(const B& b) { _x = b.y(); }
    explicit operator B() const { return B(_x); }
    [[nodiscard]] int x() const { return _x; }

private:
    int _x;
};



int main() {
    B b(10);
    A a(20);

    // B类型的对象可以通过调用A类型的单参构造
    // a = b; // 没有explicit就可以
    a = A(b);
    cout << a.x() << endl;

    // A类型对象可以调用A类型中的operator B()函数创建B类型对象
    // b = a; // 没有explicit就可以
    b = static_cast<B>(a);
    cout << b.y() << endl;

    return 0;
}
