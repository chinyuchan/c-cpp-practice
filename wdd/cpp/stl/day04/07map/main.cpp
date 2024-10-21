#include <iostream>
#include <map>

using namespace std;

class Student {
public:
    explicit Student(const int no=0, const string name="", const int age=0) :_no(no), _name(name), _age(age) {}
    // bool operator<(const Student& s) const {
    //     return _no < s._no;
    // }
    int no() const { return _no; }
    friend ostream& operator<<(ostream& os, const Student& s) {
        return os << "[" << s._no << " " << s._name << " " << s._age << "]";
    }
private:
    int _no;
    string _name;
    int _age;
};

class StudentCompare {
public:
    bool operator()(const Student& s1, const Student& s2) const {
        return s1.no() < s2.no();
    }
};

int main() {
    // 以Student类型构建红黑树，需要Student实现小于操作符
    map<Student, int, StudentCompare> students;

    Student s{1000, "Alice", 18};
    students[s] = 1000;

    students.insert(
        pair<Student,int>(Student{1001, "Bob", 20}, 1001));

    students.insert(
        make_pair(Student{1002, "Chris", 19}, 1002));

    students.insert_or_assign(
        Student{1003, "David", 21}, 1003);

    students.emplace(
        Student{1004, "Ella", 1004}, 1004);

    cout << students.count(s) << endl;

    map<Student, int>::iterator it = students.find(s);
    if (it != students.end()) {
        cout << it->first << " -> " << it->second << endl;
    }

    pair<map<Student,int>::iterator, map<Student,int>::iterator> p = students.equal_range(s);
    for (it = p.first; it != p.second; ++it) {
        cout << it->first << " , " << it->second << endl;
    }

    return 0;
}
