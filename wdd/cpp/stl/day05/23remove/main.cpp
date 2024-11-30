#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v{1, 2, 2, 3, 1, 1, 1, 2, 2, 4, 5, 1, 2};
    remove(v.begin(), v.end(), 2); // 用后面的元素覆盖要删除的元素
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
