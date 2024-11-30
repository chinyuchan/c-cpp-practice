#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v(10, 1024);
    for (auto n : v) {
        cout << n << " ";
    }
    cout << endl;

    fill(v.begin(), v.end(), 9527);
    for (auto n : v) {
        cout << n << " ";
    }
    cout << endl;

    array<int, 5> arr{};
    arr.fill(7);
    for (auto n : arr) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
