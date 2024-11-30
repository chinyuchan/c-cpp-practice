#include "list.h"

class Show {
public:
    void operator()(const int& n) {
        cout << n << ' ';
    }
};


int main() {
    //List<int> l1;

    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    List<int> l2(&arr[0], &arr[10]);

    l2.push_back(110);
    l2.push_front(120);
    // l2.print([](const int& a) {
    //     cout << a << endl;
    // });
    // l2.print(Show());
    // cout << endl;
    auto it= l2.begin();
    for(; it != l2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    --it;
    cout << *it << endl;

    cout << "-----------------------------------------------" << endl;
    for(List<int>::ReverseIterator rit = l2.rbegin(); rit != l2.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    cout << "-----------------------------------------------" << endl;
    l2.insert(++l2.begin(), {20, 20, 20, 30, 40});
    for(List<int>::Iterator it = l2.begin(); it != l2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    cout << "-----------------------------------------------" << endl;
    for (auto it = l2.begin(); it != l2.end(); ) {
        if (*it == 20) {
            it = l2.erase(it);
        }
        else {
            ++it;
        }
    }
    for(auto it = l2.begin(); it != l2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    cout << "-----------------------------------------------" << endl;
    List<int> l3(l2);
    l3.push_back(1111);
    cout << l2.size() << endl;
    cout << l3.size() << endl;
    for(auto it = l3.begin(); it != l3.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    cout << "-----------------------------------------------" << endl;
    List<int> l1 = l3;
    cout << "-----------------------------------------------" << endl;
    List<int> l4(move(l3));
    //cout << l3.size() << endl;
    for(auto it = l4.begin(); it != l4.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    return 0;
}
