#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9, 10};
    int brr[] = {4, 5, 6};
    int crr[] = {4, 5, 8};

    auto it = search(&arr[0], &arr[10], &brr[0], &brr[3]);
    if (it != &arr[10]) {
        cout << "found: " << *it << endl;
    } else {
        cout << "not found" << endl;
    }

    // 重复子元素搜索：查找是否有连续5个3
    it = search_n(&arr[0], &arr[10], 5, 3);
    if (it != &arr[10]) {
        cout << "found: " << *it << endl;
    } else {
        cout << "not found" << endl;
    }

    it = search(&arr[0], &arr[10], &crr[0], &crr[3]);
    if (it != &arr[10]) {
        cout << "found: " << *it << endl;
    } else {
        cout << "not found" << endl;
    }

    return 0;
}
