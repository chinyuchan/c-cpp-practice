#include <iostream>
#include <set>
using namespace std;


int main() {
    set<int> s{1, 3, 4, 5, 6, 7, 8, 10, 15, 16, 17};
    cout << s.count(3) << "" << s.count(2) << endl;
    cout << boolalpha << s.contains(3) << " " << s.contains(2) << endl;
    auto ret = s.find(5);
    if (ret != s.end()) {
        cout << "find: " << *ret << endl;
    }
    else {
        cout << "not found" << endl;
    }
    ret = s.find(2);
    if (ret != s.end()) {
        cout << "find: " << *ret << endl;
    }
    else {
        cout << "not found" << endl;
    }
    // 查找目标值所在的区间
    // 返回第一个不小于目标值的元素和第一个大于目标值的元素的迭代器
    pair<set<int>::iterator, set<int>::iterator> pos = s.equal_range(5);
    for (auto it = pos.first; it != pos.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    pos = s.equal_range(8);
    auto lower = s.lower_bound(11); // 首个不小于（首个大于等于）
    auto upper = s.upper_bound(11); // 首个大于
    if (lower != s.end()) {
        cout << "low_bound: " << *lower << endl;
    }
    else {
        cout << "not found" << endl;
    }
    if (upper != s.end()) {
        cout << "upper_bound: " << *upper << endl;
    }
    else {
        cout << "not found" << endl;
    }

    lower = s.lower_bound(8);
    upper = s.upper_bound(8);
    if (lower != s.end()) {
        cout << "low_bound: " << *lower << endl;
    }
    else {
        cout << "not found" << endl;
    }
    if (upper != s.end()) {
        cout << "upper_bound: " << *upper << endl;
    }
    else {
        cout << "not found" << endl;
    }
    return 0;
}
