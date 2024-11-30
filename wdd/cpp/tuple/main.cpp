#include <iostream>
#include <tuple>
#include <cmath>
using namespace  std;

struct IntDouble {
    int x;
    double y;
};

// 用于函数返回多个值
tuple<bool, double> my_sqrt(double x) {
    if (x >= 0.0) {
        return {true, sqrt(x)};
    }
    return {false, 0.0};
}

int main() {
    auto tp = tuple<char, int, double, bool>('A', 1, 2.5, false);
    int c = get<0>(tp);
    int i = get<1>(tp);
    int d = get<2>(tp);
    int b = get<3>(tp);
    cout << c << " " << i << " " << d << " " << b << endl;

    // 可以自动推断类型
    auto tp2 = tuple(1, 2.3, 'B', true);
    //结构化绑定
    auto [i2, d2, c2, b2] = tp2;
    cout << i2 << " " << d2 << " " << c2 << " " << b2 << endl;

    // 绑定为引用
    auto &[i3, d3, c3, b3] = tp2;
    i3++;
    cout << get<0>(tp2) << endl;
    auto const &[i4, d4, c4, b4] = tp2;

    // 结构化绑定可以支持任意类型
    IntDouble id = {1, 2.34};
    auto [x, y] = id;
    cout << x << " " << y << endl;

    return 0;
}
