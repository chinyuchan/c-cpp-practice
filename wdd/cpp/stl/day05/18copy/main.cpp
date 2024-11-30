#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;


int main() {
    int arr[5]{1,2,3,4,5};

    // int brr[1]{};
    // copy(&arr[0], &arr[5], &brr[0]);

    vector<int> v;
    v.resize(5);
    copy(&arr[0], &arr[5], v.begin());
    for (const int& n : v) {
        cout << n << " ";
    }
    cout << endl;

    list<int> l;
    l.resize(5);
    copy(&arr[0], &arr[5], l.begin());
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    int brr[10]{1,2,3,4,5,6,7,8,9,10};
    copy_if(&brr[0],&brr[10], l.begin(), [](int n)->bool{ return n % 2 == 0; });
    for(auto n : l) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
