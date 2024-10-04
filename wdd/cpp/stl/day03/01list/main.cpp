#include <iostream>
#include <list>
#include <vector>
using namespace std;

void show(const list<int>& l) {
    for(auto const& x : l) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    list<int> l1;
    show(l1);

    list<int> l2(5, 1024);
    show(l2);

    list<int> l3{1, 2, 3, 4, 5};
    show(l3);

    list<int> l4(5);
    show(l4);

    list<int> l5(l3.begin(), l3.end());
    show(l5);

    int arr[5] = {6, 7, 8, 9, 10};
    list<int> l6(&arr[0], &arr[5]);
    show(l6);

    list<int> l7(l6);
    show(l7);

    vector<int> v{11, 22, 33, 44, 55, 66, 77, 88, 99};
    list<int> l8(v.begin()+1, v.end()-2);
    show(l8);
    cout << l8.front() << endl;
    cout << l8.back() << endl;
    cout << l8.empty() << endl;
    cout << l8.size() << endl;

    l8.assign(15, 100);
    show(l8);
    l8.assign(5, 1024);
    show(l8);



    return 0;
}
