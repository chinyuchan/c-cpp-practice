#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

template<typename FUNC>
void fetch_data(const FUNC& func) {
    for (int i = 0; i < 10; ++i) {
        func(i);
    }
    func(1.23);
    func(4.56);
    func(7.89);
}


int main() {
    vector<int> res_i;
    vector<double> res_f;
    fetch_data([&](const auto& x) {
        using T = std::decay_t<decltype(x)>;
        if constexpr (std::is_same_v<T, int>) {
            cout << "add int: " << x << endl;
            res_i.push_back(x);
        }
        else if constexpr (std::is_same_v<T, double>) {
            cout << "add double: " << x << endl;
            res_f.push_back(x);
        }
    });
    for(int n : res_i) {
        cout << n << ' ';
    }
    cout << endl;
    for(int n : res_f) {
        cout << n << ' ';
    }
    cout << endl;
    // 立即求值
    vector<int> arr = {1, 4, 2, 8, 5, 7};
    int to_find = 5;
    int index = [&]()->int {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == to_find) {
                return i;
            }
        }
        return -1;
    }();
    cout << index << endl;

    return 0;
}
