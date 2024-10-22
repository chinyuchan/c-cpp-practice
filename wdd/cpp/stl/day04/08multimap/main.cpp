#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<int, string> m;
    m.insert(pair<int,string>{1,"Hello"});
    m.insert(make_pair<int,string>(2, "world"));
    m.insert(make_pair(3, "hi"));
    m.emplace(4, "hey");
    m.insert({
        {5, "haha"},
        {6, "hehe"}
    });

    multimap<int, string> m1{
        {7, "Alice"},
        {8, "Bob"},
        {9, "Chris"}
    };

    m.merge(m1);
    cout << m.size() << endl;
    for(const auto& p : m) {
        cout << p.first << " -> " << p.second << endl;
    }

    return 0;
}
