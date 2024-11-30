#include <iostream>
#include <list>
using namespace std;

void show(const list<int>& l) {
    for (auto const& x: l) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    list<int> l1{9, 7, 5, 3, 1};
    list l2{2, 4, 6, 8, 10}; // 类型可以不写，会自动推导

    // 将l2合并到l1
    // l2中的元素会被删除
    l1.merge(l2);
    show(l1);
    cout << l1.size() << endl; // 10
    show(l2);
    cout << l2.size() << endl; // 0
    cout << "----------------------------------" << endl;
    list l3{1, 2, 3, 4, 5};
    list l4{6, 7, 8, 9, 10};
    // 指定l3和l4的合并规则，默认的规则是升序less()
    l3.merge(l4, greater());
    show(l3); // 6 7 8 9 10 1 2 3 4 5
    cout << "----------------------------------" << endl;
    list l5{1, 2, 3, 4, 5};
    list l6{6, 7, 8, 9, 10};
    // 将l6接到l5的末尾，l6中的元素会被删除
    l5.splice(l5.end(), l6);
    show(l5);
    show(l6);
    cout << "----------------------------------" << endl;
    list l7{1, 2, 3, 4, 5};
    list l8{6, 7, 8, 9, 10};
    l7.splice(l7.begin(), l8, ++++l8.begin(), l8.end());
    show(l7); // 8 9 10 1 2 3 4 5
    show(l8);
    cout << "----------------------------------" << endl;
    list l9{0, 1, 0, 2, 0, 3, 4, 5, 6, 7, 8, 9};
    l9.remove(0);
    show(l9);
    // 按条件删除，数据类型必须支持==操作符
    l9.remove_if([](const int x)-> bool{
        return x % 2 == 0;
    });
    show(l9);

    return 0;
}