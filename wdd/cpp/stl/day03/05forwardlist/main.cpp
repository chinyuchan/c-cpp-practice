#include <iostream>
#include <forward_list>
using namespace std;

void show(const forward_list<int>& l) {
    for(auto const& x : l) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    forward_list<int> l1;
    forward_list<int> l2(5);
    forward_list<int> l3(5, 9527);
    forward_list<int> l4(l3);
    forward_list<int> l5(l4.begin(), l4.end());
    forward_list<int> l6{1, 2, 3, 4, 5};

    auto it = l6.begin();
    ++it;
    // --it; // 不支持逆向迭代

    it = l6.before_begin();
    l6.insert_after(it, 1024);
    l6.push_front(10);
    l6.push_front(20);
    show(l6); // 20 10 1024 1 2 3 4 5

    l6.pop_front();
    show(l6); // 10 1024 1 2 3 4 5

    l6.erase_after(l6.before_begin());
    show(l6); // 1024 1 2 3 4 5

    // end的下一个位置不存在，会报错
    // l6.splice_after(l6.end(), l3);

    return 0;
}
