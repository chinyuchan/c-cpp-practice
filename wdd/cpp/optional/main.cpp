#include <iostream>
#include <optional>
#include <cmath>
using namespace std;

optional<double> my_sqrt(double x) {
    if (x >=0.0) {
        return sqrt(x);
    }
    return nullopt;
}

int main() {
    auto result = my_sqrt(2.25);
    if (result.has_value()) {
        cout << result.value() << endl;
    }
    else {
        cout << "No solution" << endl;
    }

    result = my_sqrt(-1.0);
    // 和if (result.has_value())等价
    if (result) {
        cout << result.value() << endl;
    }
    else {
        cout << "No solution" << endl;
    }

    result = my_sqrt(1.44);
    // 如果optional里面没有值，就给默认值
    cout << result.value_or(0) << endl;
    result = my_sqrt(-1.44);
    cout << result.value_or(0) << endl;

    return 0;
}
