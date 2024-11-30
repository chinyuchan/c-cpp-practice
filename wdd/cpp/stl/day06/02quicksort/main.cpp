#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename IT>
void quicksort(IT beg, IT end) {
    if (beg >= end) { return; }

    IT first = beg;
    if (++first == end) { return; }

    auto key = *beg;
    auto it = partition(beg, end, [key](int n) -> bool {
        return n <= key;
    });
    first = it;
    --it;
    *beg = *it;
    *it = key;

    quicksort(beg, it);
    quicksort(first, end);
}


struct Compare1 {
    explicit Compare1(int pivot) : _pivot(pivot) {}

    bool operator()(const int& n) const {
        return n < _pivot;
    }

    int _pivot;
};

struct Compare2 {
    explicit Compare2(int pivot) : _pivot(pivot) {}

    bool operator()(const int& n) const {
        return !(_pivot < n);
    }

    int _pivot;
};

template<typename IT>
void quicksort2(IT first, IT last) {
    if (first == last) return;
    auto pivot = *next(first, distance(first, last) / 2);

    // [first,mid1)全部小于pivot，[mid1,last)全部大于等于pivot
    // auto mid1 = partition(first, last, Compare1(pivot));
    auto mid1 = partition(first, last, [pivot](const int n) -> bool {
        return n < pivot;
    });

    // [mid1,mid2)全部等于pivot，[mid2,last)全部大于pivot
    // auto mid2 = partition(mid1, last, Compare2(pivot));
    auto mid2 = partition(mid1, last, [pivot](const int n) -> bool {
        return !(pivot < n);
    });

    quicksort2(first, mid1);
    quicksort2(mid2, last);
}


int main() {
    vector<int> v{9, 2, 3, 7, 5, 0, 10, 1, 6, 4, 8};
    quicksort(v.begin(), v.end());
    for (auto const n : v) {
        cout << n << " ";
    }
    cout << endl;

    vector<int> v2{9, 2, 3, 7, 5, 0, 10, 1, 6, 4, 8};
    quicksort2(v2.begin(), v2.end());
    for (auto const n : v2) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
