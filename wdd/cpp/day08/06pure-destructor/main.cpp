#include <iostream>
using namespace std;

class A {
public:
    virtual ~A() = 0; // 语法允许，但是编译报错
};

class B : public A {
public:
    ~B() {
        // 会去调用A中的析构函数，但是A的析构函数没有定义
    }
};

int main()
{
    B b;
    return 0;
}
