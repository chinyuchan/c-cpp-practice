#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    vector<int> v1{1, 2, 3, 4, 5, 6};
    vector<int> v2{1, 2, 3, 5, 7};
    // 找出v1,v2首个不匹配的位置
    pair<vector<int>::iterator, vector<int>::iterator> p = mismatch(v1.begin(), v1.end(), v2.begin(), v2.end());
    if (p.first != v1.end() && p.second != v2.end()) {
        cout << *p.first << " " << *p.second << endl;
    }
    else {
        cout << "not match" << endl;
    }

    return 0;
}
