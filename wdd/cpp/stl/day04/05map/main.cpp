#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main() {
    char s[1024]{};
    cin.getline(s, 1024);
    cout << s << endl;

    map<string,int> m;
    stringstream ss(s);

    string word;
    while (ss >> word) {
        ++m[word];
    }

    for(const auto &p : m) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
