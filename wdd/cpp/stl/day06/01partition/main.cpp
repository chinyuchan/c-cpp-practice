#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 对[first,end)区间的元素进行划分，满足的条件的在前面，不满足的在后面
    // 返回值是第一个不满足条件的元素的迭代器
    auto it = partition(v.begin(), v.end(), [](const int n)-> bool {
        return n% 2 != 0;
    });
    cout << *it << endl;

    for(const auto n : v) {
        cout << n << " ";
    }
    cout << endl;
    bool res = is_partitioned(v.begin(), v.end(), [](const int n)-> bool { return n % 2 != 0; });
    cout << boolalpha << "is partitioned: " << res << endl;

    return 0;
}
