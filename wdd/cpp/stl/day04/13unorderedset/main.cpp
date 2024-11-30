#include <iostream>
#include <unordered_set>
using namespace std;

void show(unordered_set<int>& s) {
    for (int i = 0; i < s.bucket_count(); ++i) {
        cout << "第" << i << "号桶: ";
        for (unordered_set<int>::local_iterator lit = s.begin(i); lit != s.end(i); ++lit) {
            cout << *lit << " ";
        }
        cout << endl;
    }
}


int main() {
    unordered_set<int> s{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    cout << "size: " << s.size() << ", bucket: " << s.bucket_count() << endl;
    for(const auto& n : s) {
        cout << n << " ";
    }
    cout << endl;

    pair<unordered_set<int>::iterator, bool> result = s.insert(10);
    if (!result.second) {
        cout << "insert failed" << endl;
    } else {
        cout << "inserted succeed: " <<  *result.first << endl;
    }

    result = s.insert(16);
    if (!result.second) {
        cout << "insert failed" << endl;
    } else {
        cout << "inserted succeed: " <<  *result.first << endl;
    }

    s.clear();
    cout << "size: " << s.size() << ", bucket: " << s.bucket_count() << endl;

    cout << "----------------------------------------------------" << endl;
    unordered_set<int> s1{21, 42, 13, 24, 35, 100};
    show(s1);
    cout << "----------------------------------------------------" << endl;
    s1.insert({36, 17, 48, 59, 90});
    show(s1);
    cout << "----------------------------------------------------" << endl;
    s1.insert({110, 29, 63, 44, 45});
    show(s1);
    cout << "----------------------------------------------------" << endl;
    unordered_set<int> s2{0, 13, 26, 39, 52, 65, 78, 91, 104, 117, 130};
    show(s2);
    cout << "----------------------------------------------------" << endl;
    s2.rehash(29);
    show(s2);

    return 0;
}
