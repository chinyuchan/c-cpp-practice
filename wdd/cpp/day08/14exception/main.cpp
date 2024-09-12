#include <iostream>
using namespace std;

class A {
public:
    A() {
        _p1 = new int(100);
        try {
            _p2 = new int[0xFFFFFFFFFF];
        }
        catch(exception& e) {
            delete _p1; // 释放之前申请的内存
            throw e;
        }
    }
    ~A() {
        cout << "~A()" << endl;
        delete _p1;
        delete[] _p2;
    }
private:
    int* _p1;
    int* _p2;
};

int main()
{
    try {
        // 构造函数中抛出异常时，不会调用析构函数
        A a;
    }
    catch (bad_alloc& e) {
        cout << e.what() << endl;
    }
    catch (...) {
        cout << "exception thrown" << endl;
    }
    return 0;
}
