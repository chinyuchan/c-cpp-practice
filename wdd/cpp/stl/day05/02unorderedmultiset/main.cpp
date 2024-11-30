#include <iostream>
#include <unordered_set>
using namespace std;

class Employee {
public:
    explicit Employee(const int no=0, const string name="", const float salary=0) : _no(no), _name(name), _salary(salary) {}
    int no() const { return _no; }
    float salary() const { return _salary; }

    friend ostream& operator<<(ostream& os, const Employee& s) {
        return os << s._no << " " << s._name << " " << s._salary;
    }
private:
    int _no;
    string _name;
    float _salary;
};

template<>
struct std::hash<Employee> {
    int operator()(const Employee& e) const noexcept {
        return e.no();
    }
};

struct HashEmployee {
    int operator()(const Employee& e) const {
        return e.no();
    }
};

template<>
struct std::equal_to<Employee> {
    bool operator()(const Employee& e1, const Employee& e2) const {
        return e1.no() < e2.no();
    }
};

struct CompareEmployee {
    bool operator()(const Employee& e1, const Employee& e2) const {
        return e1.no() < e2.no();
    }
};

int main() {
    unordered_multiset<Employee> s;
    unordered_set<Employee, HashEmployee, CompareEmployee> s1;

    s1.insert(Employee{1001, "Alice", 10000});
    s1.insert(Employee{1002, "Bob", 8000});
    s1.insert(Employee{1003, "Cindy", 9000});
    s1.insert(Employee{1004, "Dale", 15000});
    s1.insert(Employee{1005, "Eric", 20000});

    pair<
        unordered_multiset<Employee, HashEmployee, CompareEmployee>::iterator,
        unordered_multiset<Employee, HashEmployee, CompareEmployee>::iterator
    > p = s1.equal_range(Employee{1002});
     for(auto it = p.first; it != p.second; ++it) {
         cout << it->no() << endl;
     }


    return 0;
}
