#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    random_shuffle(v.begin(), v.end());
    for (const auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
