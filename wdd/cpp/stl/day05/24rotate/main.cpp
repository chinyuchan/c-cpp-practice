#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    rotate(v.begin(), v.begin() + 4, v.end());
    for (auto n : v) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
