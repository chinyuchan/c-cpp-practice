#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool even(const int& num) {
    return num % 2 == 0;
}

struct Even {
    bool operator()(const int& num) const {
        return num % 2 == 0;
    }
};

int main() {
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{2, 4, 6, 8, 10};
    vector<int> v3{1, 3, 5, 7, 9};

    cout << boolalpha << all_of(v1.begin(), v1.end(), even) << endl;
    cout << boolalpha << any_of(v1.begin(), v1.end(), even) << endl;
    cout << boolalpha << none_of(v1.begin(), v1.end(), even) << endl;

    cout << boolalpha << all_of(v2.begin(), v2.end(), Even()) << endl;
    cout << boolalpha << any_of(v2.begin(), v2.end(), Even()) << endl;
    cout << boolalpha << none_of(v2.begin(), v2.end(), Even()) << endl;

    cout << boolalpha << all_of(v3.begin(), v3.end(), [](const int n) { return n % 2 == 0; }) << endl;
    cout << boolalpha << any_of(v3.begin(), v3.end(), [](const int n) { return n % 2 == 0; }) << endl;
    cout << boolalpha << none_of(v3.begin(), v3.end(), [](const int n) { return n % 2 == 0; }) << endl;



    return 0;
}
