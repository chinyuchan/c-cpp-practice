#include <iostream>
#include <set>
using namespace std;

void show(const multiset<int>& ms) {
    for (const auto x : ms) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    multiset<int> ms{1, 2, 1, 1, 1, 3, 4, 5, 4, 3, 2, 6, 7};
    cout << ms.size() << endl;
    show(ms);
    cout << "---------------------------------------------------" << endl;
    ms.insert(8);
    ms.insert(6);
    show(ms);
    cout << "---------------------------------------------------" << endl;
    int arr[5] = {11, 12, 13, 14, 15};
    ms.insert(&arr[0], &arr[5]);
    show(ms);
    cout << "---------------------------------------------------" << endl;
    ms.insert({20, 19, 18 ,17, 16});
    show(ms);
    cout << "---------------------------------------------------" << endl;
    ms.erase(ms.begin()); // 删除指定位置，只删除一个
    ms.erase(6); // 删除所有
    show(ms);
    cout << "---------------------------------------------------" << endl;
    multiset<int> ms2{21, 22, 23};
    ms.merge(ms2);
    show(ms);
    show(ms2);
    cout << "---------------------------------------------------" << endl;
    cout << ms.count(1) << endl;
    auto pos = ms.find(100);
    if (pos != ms.end()) {
        cout << *pos << endl;
    }
    else {
        cout << "not found" << endl;
    }
    cout << "---------------------------------------------------" << endl;
    auto p = ms.equal_range(8);
    for (auto it = p.first; it != p.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
