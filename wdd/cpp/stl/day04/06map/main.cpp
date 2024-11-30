#include <iostream>
#include <map>
using namespace std;


int main() {
    string names[4] = {"Alice", "Bob", "Chris", "David"};

    map<string, int> m;
    for (const auto& name : names) {
        m[name] = 0;
    }
    for(int i = 0; i < 10; ++i) {
        cout << "Candidate: " << endl;
        for(int j = 0; j < 4; ++j) {
            cout << "[" << j << "]" << names[j] << endl;
        }
        cout << ">>>";
        int in = 0;
        cin >> in;
        if (in < 0 || in >= 4) {
            cout << "invalid" << endl;
            continue;
        }

        m[names[in]]++;
    }

    for (const auto& p : m) {
        cout << p.first << " : " << p.second << endl;
    }


    return 0;
}
