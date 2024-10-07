#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s1{1, 9, 2, 2, 5, 4};
    pair<set<int>::iterator, bool> ret = s1.insert(3);
    if (ret.second) {
        cout << "insert success" << endl;
    } else {
        cout << "insert failed" << endl;
    }

    ret = s1.insert(5);
    if (ret.second) {
        cout << "insert success" << endl;
    } else {
        cout << "insert failed" << endl;
    }

    return 0;
}
