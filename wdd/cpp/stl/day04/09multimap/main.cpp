#include <iostream>
#include <map>
using namespace std;


int main() {
    multimap<string, double> m;
    m.insert({"Alice", 8000});
    m.insert({"Alice", 9000});
    m.insert({"Alice", 11000});
    m.insert({"Alice", 18000});

    m.insert({"Bob", 9000});
    m.insert({"Bob", 10000});
    m.insert({"Bob", 15000});
    m.insert({"Bob", 10000});

    m.insert({
        {"Chris", 8000},
        {"Chris", 9000},
        {"Chris", 10000},
        {"Chris", 16000}
    });

    m.emplace("David", 1000);
    m.emplace("David", 2000);
    m.emplace("David", 3000);
    m.emplace("David", 4000);

    for (multimap<string, double>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }

    cout << "----------------------------" << endl;

    for (multimap<string, double>::iterator it = m.begin(); it != m.end();) {
        auto p = m.equal_range(it->first);
        double sum = 0;
        for (auto beg = p.first; beg != p.second; ++beg) {
            sum += beg->second;
        }
        cout << it->first << " : " << sum << endl;
        it = p.second;
    }

    return 0;
}
