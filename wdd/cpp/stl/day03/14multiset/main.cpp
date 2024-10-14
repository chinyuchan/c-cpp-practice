#include <iostream>
#include <set>
using namespace std;

class Student {
public:
    explicit Student(const int no=0, string name="", const int age=0) : _no(no), _name(name), _age(age) {}

    [[nodiscard]] int no() const {
        return _no;
    }

    [[nodiscard]] string name() const {
        return _name;
    }

    friend ostream& operator<<(ostream& os, const Student& s) {
        return os << s._no << " " << s._name << " " << s._age;
    }

private:
    int _no;
    string _name;
    int _age;
};

class StudentCompare {
public:
    bool operator()(const Student& s1, const Student& s2) const {
        return s2.no() < s1.no();
    }
};

void show(const multiset<Student, StudentCompare>& ms) {
    for(const auto& s : ms) {
        cout << s << endl;
    }
}

int main() {
    multiset<Student, StudentCompare> ms{
        Student{1005, "David", 18},
        Student{1002, "Alice", 19},
        Student{1000, "Jack", 18},
        Student{1003, "Bob", 16},
        Student{1001, "Tom", 17},
        Student{1000, "Charlie", 17},
    };
    show(ms);
    cout << "-----------------------------------------" << endl;
    auto it = ms.find(Student{1001});
    cout << *it << endl;

    ms.erase(Student{1001});
    it = ms.find(Student{1001});
    if (it != ms.end()) {
        cout << *it << endl;
    }
    else {
        cout << "not found" << endl;
    }
    cout << "-----------------------------------------" << endl;
    ms.insert(Student{1003, "Ela", 16});
    ms.insert(Student{1003, "Funny", 16});
    ms.insert(Student{1003, "Grey", 16});
    ms.insert(Student{1003, "Henry", 16});
    cout << ms.count(Student{1003}) << endl;
    show(ms);
    cout << "-----------------------------------------" << endl;
    auto p = ms.equal_range(Student{1003});
    for(auto it = p.first; it != p.second; ++it) {
        cout << *it << endl;
    }
    cout << "-----------------------------------------" << endl;
    for(it = ms.begin(); it != ms.end(); ++it) {
        if (it->no() == 1003 && it->name() == string("Funny")) {
            ms.erase(it);
            break;
        }
    }
    show(ms);
    return 0;
}
