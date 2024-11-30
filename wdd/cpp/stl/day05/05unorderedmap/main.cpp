#include <iostream>
#include <unordered_map>
using namespace std;

class A {
public:
    explicit A(const int x=0, const int y=0): _x(x), _y(y) {}
    int x() const { return _x; }
    int y() const { return _y; }

    friend ostream& operator<<(ostream& os, const A& a) {
        return os << "("<< a._x << "," << a._y << ")";
    }

private:
    int _x;
    int _y;
};

// template<>
// struct std::hash<A> {
//     int operator()(const A& a) const noexcept {
//         return a.x() % 11;
//     }
// };

struct HashA {
    int operator()(const A& a) const {
        return a.x() % 11;
    }
};

struct EqualA {
    int operator()(const A& a, const A& b) const {
        return a.x() == b.x() && a.y() == b.y();
    }
};

int main() {
    unordered_map<int, A> m;
    m[1] = A{1, 1};
    for(const auto& p: m) {
        cout << p.first << " => " << p.second << endl;
    }

    cout << "-------------------------------------------" << endl;

    unordered_map<A, int, HashA, EqualA> m2;
    // 都在同一个桶中
    A a = A{1, 1};
    m2[a] = 1;
    A a1 = A{12,12};
    m2[a1] = 12;
    A a2 = A{23,23};
    m2[a2] = 23;

    size_t buckets = m2.bucket_count();
    for (size_t i = 0; i < buckets; ++i) {
        cout << "Bucket[" << i << "] has " << m2.bucket_size(i) << " elements: ";
        for(auto it = m2.begin(i); it != m2.end(i); ++it) {
            cout << it->first << " => " << it->second << "  ";
        }
        cout << endl;
    }

    return 0;
}
