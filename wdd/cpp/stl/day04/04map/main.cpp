#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int,string> m1{
        {1, "hello"},
        {2, "world"},
        {3, "hi"}
    };

    map<int,string> m2;
    auto node = m1.extract(1);
    m2.insert(move(node));
    cout << m1.size() << endl;
    cout << m2.size() << endl;

    return 0;
}
