#include <iostream>
using namespace std;

class Father {
public:
    Father& operator=(const Father& f) {
        cout << "Father& operator=(const Father&)" << endl;
        return *this;
    }
};

class Son : public Father {

};

int main() {
    Father f;
    Son s;

    // 子类 is a 父类
    // 子类对象就是父类对象
    f = s; // 实际是调用父类的拷贝赋值函数，即可以用父类引用来引用子类对象

    return 0;
}
