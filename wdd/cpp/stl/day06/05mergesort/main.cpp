#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename IT>
void merge_sort(IT beg, IT end) {
    if (distance(beg, end) <= 1) {
        return;
    }
    auto mid = next(beg, distance(beg, end) / 2);
    merge_sort(beg, mid);
    merge_sort(mid, end);
    inplace_merge(beg, mid, end);
}

int main() {
    vector<int> v{8, 1, 9, 2, 3, 8, 4, 0, 5, 7, 6};
    merge_sort(v.begin(), v.end());
    for (int n : v) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}