#include <iostream>
#include <unordered_set>
using namespace std;


int main() {
    unordered_set<int> s{1, 2, 3, 4, 5, 2, 3, 6, 5, 4, 1, 0};
    cout << s.size() << endl;
    cout << s.bucket_count() << endl;
    s.insert({11, 12, 13, 14, 15, 16, 17});
    cout << s.bucket_count() << endl;
    cout << "最大加载因子: " << s.max_load_factor() << endl;
    cout << "目前加载因子: " << s.load_factor() << endl;

    unordered_set<int> s1;
    cout << s1.bucket_count() << endl;
    s1.insert(0);
    s1.insert(1);
    cout << s1.bucket_count() << endl;

    return 0;
}
