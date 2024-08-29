#include <iostream>
using namespace std;

enum Number {
    ONE,
    TWO,
    THREE
};

template<int N=1>
void print_num() {
    for(int i = 0; i < N; ++i) {
        cout << i << ' ';
    }
    cout << endl;
}

int sum_to(int n, bool debug) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += i;
        if (debug) { // 如果为false，还是会生成指令，消耗CPU时间
            cout << n << ' ' << endl;
        }
    }
    return res;
}

template<bool debug>
int sum_to(int n) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += i;
        if constexpr (debug) { // 如果为false，编译器优化会去掉这三行代码，更高效
            cout << n << ' ' << endl;
        }
    }
    return res;
}

int main() {
    print_num();
    print_num<5>();
    print_num<5>();
    print_num<THREE>();

    cout << sum_to<true>(5) << endl;
    cout << sum_to<false>(5) << endl;

    return 0;
}
