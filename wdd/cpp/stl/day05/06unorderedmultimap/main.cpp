#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_multimap<int, string> m;

    m.insert(std::make_pair(1, "Alice"));
    m.insert(std::make_pair(2, "Bob"));
    m.insert(std::make_pair(3, "Cindy"));
    m.emplace(4, "Dale");
    m.emplace(5, "Ella");
    m.emplace(6, "Frank");
    m.erase(6);

    size_t bucket_count = m.bucket_count();
    cout << "bucket count: " << bucket_count << endl;

    // 插入相同的key
    auto result = m.insert({1, "Grace"});
    if (result != m.end()) {
        cout <<"insert succeed" << endl;
    } else {
        cout << "insert failed" << endl;
    }

    // 插入哈希值相同的key，会落入同一个桶
    result = m.insert({14, "Helen"});
    if (result != m.end()) {
        cout <<"insert succeed" << endl;
    } else {
        cout << "insert failed" << endl;
    }

    if (m.find(1) != m.end()) {
        cout << "found" << endl;
    }

    cout << "--------------------------------------" << endl;

    auto range = m.equal_range(1);
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << "--------------------------------------" << endl;

    for (const auto& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "--------------------------------------" << endl;

    for (size_t i = 0; i < bucket_count; ++i) {
        cout << "Bucket[" << i << "]: ";
        for (auto it = m.begin(i); it != m.end(i); ++it) {
            cout << "(" << it->first << "=>" << it->second << ") ";
        }
        cout << endl;
    }

    return 0;
}
