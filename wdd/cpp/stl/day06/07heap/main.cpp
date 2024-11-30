#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void show(const vector<int>& v) {
    for (int n: v) {
        cout << n << " ";
    }
    cout << endl;
}
int main() {
    vector<int> v{3,1,2,9,0,1,8,4,5,7,6};
    vector<int> vs(v);
    cout << boolalpha << is_heap(v.begin(), v.end()) << endl;
    cout << boolalpha << is_heap(vs.begin(), vs.end(), greater<int>()) << endl;
    auto last = is_heap_until(v.begin(), v.end());
    for (auto it = v.begin(); it != last; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    make_heap(v.begin(), v.end());
    show(v);

    make_heap(vs.begin(), vs.end(), greater<int>());
    show(v);

    v.push_back(7);
    cout << is_heap(v.begin(), v.end()) << endl;
    push_heap(v.begin(), v.end());
    cout << is_heap(v.begin(), v.end()) << endl;

    vs.push_back(1);
    cout << is_heap(vs.begin(), vs.end(), greater<int>());
    push_heap(vs.begin(), vs.end(), greater<int>());
    cout << is_heap(vs.begin(), vs.end(), greater<int>());

    pop_heap(v.begin(), v.end());
    show(v);
    cout << is_heap(v.begin(), v.end()) << endl;
    v.pop_back();
    cout << is_heap(v.begin(), v.end()) << endl;

    pop_heap(vs.begin(), vs.end(), greater<int>());
    show(vs);
    vs.pop_back();
    cout << is_heap(vs.begin(), vs.end(), greater<int>());

    sort_heap(v.begin(), v.end());
    show(v);
    sort_heap(vs.begin(), vs.end(), greater<int>());
    show(vs);

    return 0;
}