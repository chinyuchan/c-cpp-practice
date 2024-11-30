#include <iostream>
#include <map>
using namespace std;

template<typename T1, typename T2>
void show(const map<T1, T2>& m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }
}

int main() {
    map<int,string> m{
        pair<int,string>{1, "hey"},
        pair<int,string>{2, "hi"},
    };
    m[3] = "hello";
    m[4] = "world";
    cout << "size: " << m.size() << endl;
    show(m);
    cout << "-----------------------------------------" << endl;
    try {
        m.at(100); // 若key不存在，会抛出异常
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
    m[30]; // 若key不存在，会构造默认值插入
    show(m);

    auto it = m.begin();
    // it->first = 100; // key具有常属性，不允许修改
    it->second = "ha";

    return 0;
}
