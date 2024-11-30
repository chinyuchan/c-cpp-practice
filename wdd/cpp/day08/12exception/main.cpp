#include <iostream>
#include <exception>
#include <vector>
using namespace std;

// throw(...)这种写法不好
void run() throw(bad_alloc, bad_cast, out_of_range) {
    new int[0xFFFFFFFFFF];
    vector<int> v(10);
    v.at(10);

    // 抛出throw()说明以外的异常类型，在try-catch中无法捕获
    //throw int(1024);
}

// C++的新关键字，用于替换throw()，表示不抛出异常
void foo() noexcept {}

// noexcept和noexcept(true)作用相同
void foo2() noexcept(true) {}

// noexcept(false)表示函数抛出（任意类型）异常
void bar() noexcept(false) {
    new int[0xFFFFFFFFFF];
}

int main()
{
    try {
        // run();
        bar();
    }
    catch (bad_alloc& e) {
        cout << e.what() << endl;
    }
    catch (bad_cast& e) {
        cout << e.what() << endl;
    }
    catch (out_of_range& e) {
        cout << e.what() << endl;
    }
    catch (int i) { // 无法捕获
        cout << i << endl;
    }
    return 0;
}
