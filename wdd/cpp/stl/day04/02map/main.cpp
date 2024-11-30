#include <iostream>
#include <map>
using namespace std;


int main() {
    map<int,string> m;
    // 插入成功时，迭代器就是插入的k-v对的迭代器
    pair<map<int,string>::iterator, bool> p = m.insert(pair<int,string>{1,"one"});
    if (p.second) {
        cout << "insert ok, " << p.first->first << " -> " << p.first->second << endl;
    } else {
        cout << "insert failed" << endl;
    }

    p = m.insert(make_pair(2, "two"));
    if (p.second) {
        cout << "insert ok, " << p.first->first << " -> " << p.first->second << endl;
    } else {
        cout << "insert failed" << endl;
    }

    // key已经存在，插入失败
    p = m.insert(make_pair<int, string>(2, "twotwo"));
    if (p.second) {
        cout << "insert ok, " << p.first->first << " -> " << p.first->second << endl;
    } else {
        cout << "insert failed" << endl;
    }
    cout << "----------------------------------------------" << endl;
    map<int, string> m1;
    m1.insert(m.begin(), m.end());
    cout << "m1 size: " << m1.size() << endl;
    for (auto const& kv: m1) {
        cout << kv.first << " -> " << kv.second << endl;
    }
    cout << "----------------------------------------------" << endl;
    for (map<int, string>::iterator it = m1.begin(); it != m1.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }
    cout << "----------------------------------------------" << endl;
    m1.insert({
        {3, "three"},
        {4, "four"}
    });
    m1.insert({5, "five"});
    for (auto const& kv: m1) {
        cout << kv.first << " -> " << kv.second << endl;
    }

    p = m1.insert_or_assign(6, "six");
    if(p.second) {
        cout << "insert ok, " << p.first->first << " -> " << p.first->second << endl;
    } else {
        cout << "insert failed" << endl;
    }
    p = m1.insert_or_assign(6, "sixsixsix");
    if(p.second) {
        cout << "insert ok, " << p.first->first << " -> " << p.first->second << endl;
    } else {
        cout << "insert failed, " << p.first->first << " -> " << p.first->second << endl;
    }
    return 0;
}
