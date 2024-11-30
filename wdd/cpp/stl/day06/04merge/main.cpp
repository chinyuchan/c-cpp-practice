#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    vector<int> v1{1, 8, 4, 2, 9, 3, 5};
    vector<int> v2{2, 3, 8, 9, 1, 0, 6};
    vector<int> v3;
    v3.resize(v1.size()+v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for (auto n : v3) {
        cout << n << " ";
    }
    cout << endl;

    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), greater<int>());
    for (auto n : v3) {
        cout << n << " ";
    }
    cout << endl;

    vector<int> v4{1, 9, 0, 2, 6, 3, 4, 7, 8, 2, 0, 3, 8};
    auto mid = next(v4.begin(), distance(v4.begin(), v4.end())/2);
    sort(v4.begin(), mid);
    sort(mid, v4.end());
    for (auto n : v4) {
        cout << n << " ";
    }
    cout << endl;

    inplace_merge(v4.begin(), mid, v4.end());
    for (auto n : v4) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}