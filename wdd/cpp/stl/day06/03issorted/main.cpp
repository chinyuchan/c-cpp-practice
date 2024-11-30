#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{5, 4, 3, 2, 1};
    cout << boolalpha << is_sorted(v1.begin(), v1.end()) << endl;
    cout << boolalpha << is_sorted(v2.begin(), v2.end()) << endl;
    cout << boolalpha << is_sorted(v2.begin(), v2.end(), greater<int>()) << endl;

    vector<int> v3{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    auto last = is_sorted_until(v3.begin(), v3.end());
    for (auto it = v3.begin(); it != last; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    vector<int> v4{9, 3, 12, 23, 7, 0, 1, 10, 16, 15, 6};
    // 找最小(大)的N个元素，排在前面，后面的无序
    partial_sort(v4.begin(), v4.begin()+5, v4.end());
    for (auto n : v4) {
        cout << n << " ";
    }
    cout << endl;

    vector<int> v5{7, 9, 3, 0, 1, 6, 8, 4, 6, 2};
    // 找第N小(大)的元素
    nth_element(v5.begin(), v5.begin()+4, v5.end());
    for (auto n : v5) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
