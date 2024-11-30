#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int arr[5]{1, 2, 3, 4, 5};
    int brr[5]{};
    move(&arr[0], &arr[5], &brr[0]);
    for(auto n : arr) {
        cout << n << " ";
    }
    cout << endl;
    for(auto n : brr) {
        cout << n << " ";
    }
    cout << endl;

    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2(5);
    move(v1.begin(), v1.end(), v2.begin());
    for(auto n : v1) {
        cout << n << " ";
    }
    cout << endl;
    for(auto n : v2) {
        cout << n << " ";
    }
    cout << endl;


    return 0;
}
