#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    vector<int> v1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    shift_left(v1.begin(), v1.end(), 4);
    for (const auto n : v1) {
        cout << n << " ";
    }
    cout << endl;

    vector<int> v2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    shift_right(v2.begin(), v2.end(), 4);
    for (const auto n : v2) {
        cout << n << " ";
    }
    cout << endl;


    return 0;
}
