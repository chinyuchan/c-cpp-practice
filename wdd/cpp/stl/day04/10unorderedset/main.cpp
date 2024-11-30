#include <iostream>
#include <unordered_set>
using namespace std;


int main() {
    unordered_set<int> s{1, 2, 3, 4, 5, 2, 3, 6, 5, 4, 1, 0};
    cout << "size: " << s.size() << endl;
    cout << "bucket count: " << s.bucket_count() << endl;
    s.insert({11, 12, 13, 14, 15, 16, 17});
    cout << s.bucket_count() << endl;
    cout << "最大加载因子: " << s.max_load_factor() << endl;
    cout << "目前加载因子: " << s.load_factor() << endl;

    unordered_set<int> s1;
    cout << "bucket count: " << s1.bucket_count() << endl;
    s1.insert(0);
    s1.insert(1);

    // 相同的key插入失败
    pair<unordered_set<int>::iterator, bool> result = s1.insert(1);
    if (result.second) {
        cout << "insert succeed" << endl;
    }
    else {
        cout << "insert failed" << endl;
    }

    // 插入哈希值相同的元素，落在同一个桶中
    result = s1.insert(14);
    if (result.second) {
        cout << "insert succeed" << endl;
    }
    else {
        cout << "insert failed" << endl;
    }

    auto bucket_count = s1.bucket_count();
    cout << "bucket count:" << bucket_count << endl;
    for (size_t i = 0; i < bucket_count; i++) {
        cout << "Bucket[" << i << "] :";
        for (auto it = s1.begin(i); it != s1.end(i); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}
