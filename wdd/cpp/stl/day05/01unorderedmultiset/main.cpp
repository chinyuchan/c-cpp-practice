#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_multiset<int> s{5, 1, 4, 2, 2, 3, 4, 5, 4, 3};
    for(const auto& n : s) {
        cout << n << " ";
    }
    cout << endl;

    cout << s.bucket_count() << endl;
    for (int i = 0; i < s.bucket_count(); ++i) {
        cout << "第" << i << "号桶: ";
        for (unordered_multiset<int>::local_iterator lit = s.begin(i); lit != s.end(i); ++lit) {
            cout << *lit << " ";
        }
        cout << endl;
    }

    return 0;
}
