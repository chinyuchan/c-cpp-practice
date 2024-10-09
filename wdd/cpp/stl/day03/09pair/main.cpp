#include <iostream>
#include <utility>
using namespace std;

int main() {
    pair<int, string> p1(10, "hello");
    cout << p1.first << " " << p1.second << endl;

    pair<int, bool> p2 = make_pair<int, bool>(20, true);
    cout << p2.first << " " << p2.second << endl;

    auto [fst, snd] = make_pair<int, bool>(30, "world");
    cout << fst << " " << snd << endl;



    return 0;
}
