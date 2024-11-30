#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> s{1, 2, 3, 4, 5, 9, 8, 7, 11, 13, 15, 18};
    cout << s.size() << endl;
    for(const auto& n : s) {
        cout << n << " ";
    }
    cout << endl;

    for(unordered_set<int>::const_iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for(int i = 0; i < s.bucket_count(); ++i) {
        cout << "Bucket " << i << "(" << s.bucket_size(i) << "): ";
        for (unordered_set<int>::const_local_iterator lit = s.begin(i); lit != s.end(i); ++lit) {
            cout << *lit << " ";
        }
        cout << endl;
    }

    return 0;
}
