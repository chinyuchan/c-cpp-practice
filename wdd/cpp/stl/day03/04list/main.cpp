#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void show(const list<int>& l) {
    for(auto const& x: l) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    list l1{2, 3, 8, 1, 0, 7, 9, 6, 5, 4};

    // 不能使用全局的sort，该函数要求迭代器支持减法（随机迭代）
    // sort(l1.begin(), l1.end()); // ERROR

    l1.sort();
    show(l1);

    list l2{2, 3, 8, 1, 0, 7, 9, 6, 5, 4};
    l2.sort(greater());
    show(l2);

    l2.reverse();
    show(l2);

    return 0;
}