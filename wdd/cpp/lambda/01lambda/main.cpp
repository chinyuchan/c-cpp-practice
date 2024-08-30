#include <iostream>
using namespace std;

template<typename T>
void call(T func) {
    cout << func(1, 2) << endl;
}

auto make_two_times() {
    return [](int n) -> int {
        return n * 2;
    };
}

int main() {
    int x = 10, y = 20;
    // []空列表，不能访问任何外部变量
    auto func1 = [](int a, int b) -> int {
        // return x + y;
        return a+b;
    };
    cout << "sizeof(func1) = " << sizeof(func1) << endl;
    cout << typeid(func1).name() << endl;
    int result = func1(10, 20);
    cout << result << endl;
    call(func1);

    // [&]传引用，可以在lambda表达式中修改外部变量
    auto func2 = [&](int a, int b) -> int {
        x += 1;
        y += 2;
        return a + b + x + y;
    };
    cout << "sizeof(func2) = " << sizeof(func2) << endl;
    cout << func2(1,2) << endl; // 36
    cout << "x = " << x << endl; // 11
    cout << "y = " << y << endl; // 12

    // [=]传值，将外部变量拷贝一份（临时变量）到lambda表达式中，因此不能修改
    auto func3 = [=](int a, int b) -> int {
        // ++x;// ERROR
        return a + b + x + y;
    };
    cout << func3(10, 20) << endl; // 63


    auto two_times = make_two_times();
    cout << two_times(2) << endl;


    return 0;
}