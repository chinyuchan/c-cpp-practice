#include <iostream>
#include <set>
#include <typeinfo>
using namespace std;

void show(const set<int>& s) {
    for(const int& n: s) { // 必须常引用
        cout << n << ' ';
    }
    cout << endl;
}

int main() {
    set<int> s{1, 2, 3, 4, 5};
    s.insert(s.begin(), 0); // 效率高
    s.insert(s.begin(), 100); // 效率低
    show(s);
    s.erase(s.begin());
    s.erase(4);
    show(s);

    auto sn = s.extract(100);
    show(s);
    cout << typeid(sn).name() << endl;

    return 0;
}

