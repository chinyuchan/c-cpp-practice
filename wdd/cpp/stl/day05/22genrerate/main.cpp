#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/ranges_algo.h>
using namespace std;

struct Prime {
    explicit Prime(int n = 2) : _n(n) {}

    bool is_prime() const {
        for (int i = 2; i <= _n/2; i++) {
            if (_n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int operator()() const {
        while(!is_prime()) {
            ++_n;
        }
        return _n++;
    }

    mutable int _n;
};

static int n = 100;
int number() {
    return ++n;
}

int main() {
    vector<int> v;
    v.resize(100);
    generate(v.begin(), v.end(), Prime(2));
    for (auto n : v) {
        cout << n << " ";
    }
    cout << endl;

    vector<int> v1;
    v1.resize(20);
    generate(v1.begin(), v1.end(), number);
    for (auto n : v1) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
