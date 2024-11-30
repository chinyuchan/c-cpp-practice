#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 不会自动退化成int*
    // int* p = arr; // ERROR

    array<int, 10> brr = arr;
    for(auto const& x: brr) {
        cout << x << " ";
    }
    cout << endl;

    array<int, 10> crr;
    crr = arr;
    for(auto const& x: crr) {
        cout << x << " ";
    }
    cout << endl;

    // 不会越界检查，越界会返回未定义的值
    cout << arr[10] << endl;
    try {
        // 会进行越界检查，越界会抛出异常
        cout << arr.at(10) << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
    // 第一个元素
    cout << "first element: " << arr.front() << endl;
    // 最后一个元素
    cout << "last element: " << arr.back() << endl;
    // 返回底层数组
    int* p = arr.data();
    cout << *(p+1) << endl;
    cout << boolalpha << "empty: " << arr.empty() << endl;
    cout << "size: " << arr.size() << endl;
    cout << "max_size: " << arr.max_size() << endl;

    array<int, 0> drr;
    cout << "empty: " << drr.empty() << endl; // true
    array<int, 10> err;
    err.fill(1); // 填充
    for(auto const& x: err) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
