#include <iostream>
#include <list>
using namespace std;
void show(const list<int>& l) {
    for(auto const& x: l) {
        cout << x << " ";
    }
    cout << endl;
}
int main() {
    list l1{1, 1, 1, 2, 1, 3, 3, 3, 4, 5, 6, 7};
    // 删除连续重复的元素
    l1.unique();
    show(l1); // 1 2 1 3 4 5 6 7

    list l2{1, 3, 3, 3, 4, 5, 7, 9, 12, 14, 15, 17};
    // 删除后一个比前一个大2的元素
    l2.unique([](int a, int b)->bool {
        return b - a == 2;
    });
    show(l2); // 1 4 5 9 12 15

    return 0;
}
