#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    set<int> s1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    set<int> s2{2, 4, 6};
    cout << boolalpha << includes(s1.begin(), s1.end(), s2.begin(), s2.end()) << endl;

    vector<int> v1{1, 9, 4, 8, 6, 0, 3, 2};
    vector<int> v2{2, 4, 6};
    cout << boolalpha << includes(v1.begin(), v1.end(), v2.begin(), v2.end()) << endl;

    vector<int> v3;
    v3.resize(10);
    set<int> s3{2, 4, 6, 7, 8, 10, 12};
    auto last = set_difference(s1.begin(), s1.end(), s3.begin(), s3.end(),v3.begin());
    for (auto it = v3.begin(); it != last; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    multiset<int> ms1{1, 1, 1, 2, 2, 3, 3, 4};
    multiset<int> ms2{1, 2, 2, 3};
    last = set_difference(ms1.begin(), ms1.end(), ms2.begin(), ms2.end(),v3.begin());
    for (auto it = v3.begin(); it != last; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}