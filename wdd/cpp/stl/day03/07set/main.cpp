#include <iostream>
#include <set>
using namespace std;


template<typename T=int, typename C=less<T>>
void show(const set<T, C> &s) {
    for(auto const& x : s) {
        cout << x << " ";
    }
    cout << endl;
}

class Student {
public:
    explicit Student(const int no=0, string name="", const int age=0) : _no(no), _name(name), _age(age) {}
    bool operator<(const Student& s) const {
        return _age < s._age;
    }

    friend ostream& operator<<(ostream& os, const Student& s) {
        return os << s._no << " " << s._name << " " << s._age;
    }
private:
    int _no;
    string _name;
    int _age;
};


int main() {
    // 相同的不会插入
    const set<int> s {1, 2, 2, 5, 4, 3, 6, 6, 7, 7, 8, 8, 9, 9};
    cout << s.size() << endl; // 9
    show(s);

    // 按升序
    const set<int, greater<>> s2{1, 2, 2, 3, 4, 5, 6, 6, 7, 7, 8, 8, 9, 9};
    show(s2);

    set<Student> students{
        Student(1001, "Jack", 28),
        Student(1002, "Tom", 20)
    };

    // 能找到，只要按照operator<中的比较字段就可以
    set<Student>::const_iterator it = students.find(Student(1001,"Alice",28));
    cout << *it << endl;
    for(auto it = students.begin(); it != students.end(); it++) {
        // set的迭代器都有常属性，不允许修改
        // *it = Student(777,"Hello", 0);
        cout << *it << endl;
    }

    return 0;
}
