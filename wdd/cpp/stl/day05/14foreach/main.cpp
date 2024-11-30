#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v{1, 3, 4, 7, 9, 8, 2, 6, 5};

    // 遍历所有元素，将每个元素作为参数，调第三个参数
    for_each(v.begin(), v.end(), [](int i) { cout << i << " "; });
    cout << endl;

    // 遍历前n个元素，将每个元素作为参数，调第三个参数
    for_each_n(v.begin(), 5, [](int i) { cout << i << " "; });
    cout << endl;

    // 统计2的个数
    cout << count(v.begin(), v.end(), 2) << endl;

    // 统计满足条件的个数
    cout << count_if(v.begin(), v.end(), [](const int i){ return i % 2 == 0; } ) << endl;

    return 0;
}
