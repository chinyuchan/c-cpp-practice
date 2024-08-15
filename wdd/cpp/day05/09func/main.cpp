#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show(const vector<int>& v) {
    for(auto const n : v) {
        cout << n << ' ';
    }
    cout << endl;
}

bool cmp(const int& a, const int& b) { return a < b; }

class Compare {
public:
    bool operator()(const int& a, const int& b) const { return a < b; }
};

int main() {
    vector<int> v = {1, 9, 8, 5, 2, 3, 6, 4, 0, 7};
    sort(v.begin(), v.end()); // 默认按从小到大排序
    show(v);

    v = {1, 9, 8, 5, 2, 3, 6, 4, 0, 7};
    sort(v.begin(), v.end(), greater<>());
    show(v);

    v = {1, 9, 8, 5, 2, 3, 6, 4, 0, 7};
    sort(v.begin(), v.end(), less<>());
    show(v);

    v = {1, 9, 8, 5, 2, 3, 6, 4, 0, 7};
    sort(v.begin(), v.end(), cmp); // 函数指针
    show(v);

    v = {1, 9, 8, 5, 2, 3, 6, 4, 0, 7};
    sort(v.begin(), v.end(), Compare()); // 匿名函数对象
    show(v);


    return 0;
}
