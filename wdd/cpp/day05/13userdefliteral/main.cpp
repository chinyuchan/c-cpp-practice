#include <iostream>
using namespace std;

class Temperature {
public:
    explicit Temperature(long double kelvin) : _kelvin(kelvin) {}
    // 当某个声明被nodiscard属性标记时，如果返回值没有被使用，‌编译器会生成警告，这个属性的目的是提醒开发者注意检查函数的返回值
    // 当函数返回的是类或结构的引用或指针时，‌nodiscard属性是无效的
    [[nodiscard("请使用返回值")]] long double kelvin() const{ return _kelvin; }
private:
    long double _kelvin;
};

Temperature operator "" _C(long double celsius) {
    return Temperature(celsius + 273);
}

Temperature operator "" _F(long double fahrenheit) {
    return Temperature((fahrenheit+459.67) * 5 / 9);
}

int main() {
    Temperature k1 = 31.73_F;
    Temperature k2 = 0.0_C;
    k1.kelvin(); // warning
    cout << k2.kelvin() << endl;

    return 0;
}
