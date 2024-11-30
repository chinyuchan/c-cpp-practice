#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, string> phone_book;
    phone_book["Alice"] = "1234568";
    phone_book.insert(pair<string,string>("Bob", "1234567"));
    phone_book.insert(make_pair("Cindy", "1123499"));
    phone_book.emplace("Dale", "43859348");

    for (const auto& p : phone_book) {
        cout << p.first << " " << p.second << endl;
    }

    unordered_map<string, string>::iterator it;
    for (it = phone_book.begin(); it != phone_book.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
