#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> m;
    cout << m[0] << endl; // 不存在，就给默认值
    m[1] = 1;
    try {
        m.at(2); // 会抛出异常
    } catch (exception& e) {
        cout << e.what() <<endl;
    }

    m[3] = 3;
    m.insert(pair<int, int>{4,4});
    m.insert(make_pair(5,5));
    m.insert_or_assign(6, 6);
    m.insert_or_assign(6, 60);
    m.emplace(7, 7);
    m.try_emplace(8, 8);

    // 相同的key插入失败
    pair<unordered_map<int, int>::iterator,bool> result = m.insert({8, 80});
    if (result.second) {
        cout << "insert succeed" << endl;
    } else {
        cout << "insert failed" << endl;
    }

    // 插入key哈希值相同的值，会落在同一个桶中
    result = m.insert({14, 14});
    if (result.second) {
        cout << "insert succeed" << endl;
    } else {
        cout << "insert failed" << endl;
    }
    for (auto &[fst, snd] : m) {
        cout << fst << " => " << snd << endl;
    }

    cout << "---------------------------------------------" << endl;
    size_t bucket_size = m.bucket_count();
    cout << "bucket count: " << bucket_size << endl;
    for (size_t i = 0; i < bucket_size; ++i) {
        cout << "Bucket[" << i << "]: ";
        for (auto it = m.begin(i); it != m.end(i); ++it) {
            cout << "(" << it->first << "=>" << it->second << ") ";
        }
        cout << endl;
    }

    return 0;
}
