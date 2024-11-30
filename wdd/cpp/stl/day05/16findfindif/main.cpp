#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    vector<int> v{20, 23, 10, 17, 26, 26, 33, 50};

    //找17的位置
    vector<int>::iterator it = find(v.begin(), v.end(), 17);
    if (it != v.end()) {
        cout << *it << endl;
    } else {
        cout << "not found" << endl;
    }

    // 找第一个奇数的位置
    it = find_if(v.begin(), v.end(), [](int i){ return i % 2 != 0; });
    if (it != v.end()) {
        cout << *it << endl;
    } else {
        cout << "not found" << endl;
    }

    // 找第一个不满足条件的元素
    it = find_if_not(v.begin(), v.end(), [](int i){ return i % 2 == 0; });
    if (it != v.end()) {
        cout << *it << endl;
    } else {
        cout << "not found" << endl;
    }

    // 找出相邻元素相等的位置（相邻元素是否当等或满足某个条件）
    it = adjacent_find(v.begin(), v.end());
    if (it != v.end()) {
        cout << *it << endl; // 26
    } else {
        cout << "not found" << endl;
    }

    it = adjacent_find(v.begin(), v.end(), [](int x, int y){ return y - x == 7; });
    if (it != v.end()) {
        cout << *it << endl; // 10
    } else {
        cout << "not found" << endl;
    }


    return 0;
}
