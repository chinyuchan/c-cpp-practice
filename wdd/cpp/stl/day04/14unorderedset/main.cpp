#include <iostream>
#include <unordered_set>
using namespace std;

void show(unordered_set<int>&s) {
    cout << "load factor: " << s.load_factor() << ", max load factor: " << s.max_load_factor() << endl;
    cout << "bucket count: " << s.bucket_count() << endl;

    for (int i = 0; i < s.bucket_count(); ++i) {
        for (unordered_set<int>::local_iterator lit = s.begin(i); lit != s.end(i); ++lit) {
            cout << *lit << " ";
        }
        cout << endl;
    }
}

int main() {
    unordered_set<int> s;
    for (int i = 0; i < 13; ++i) {
        s.insert(i);
    }
    show(s);

    s.max_load_factor(1.5);
    s.insert(14);
    show(s);


    return 0;
}
