#include <iostream>
#include <set>
using namespace std;

void show(const set<int>& s) {
    for (const auto x: s) {
        cout << x << " ";
    }
    cout << endl;
}
int main() {
    set<int> s1{1, 2, 3, 4, 5};
    set<int> s2{2, 3, 6, 7, 8};
    // 将s2合并到s1，如果s1中有的数，则不会保留在s2中
    s1.merge(s2);
    show(s1);
    show(s2);

    return 0;
}
