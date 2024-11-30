#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    transform(v.begin(), v.end(), v.begin(), [](int n) -> int { return n * n; });
    for (auto n : v) {
        cout << n << " ";
    }
    cout << endl;

    vector<int> v2(10, 0);
    transform(v.begin(), v.end(), v2.begin(), [](int n) -> int { return 100 + n; });
    for (auto n : v2) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
