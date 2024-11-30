#include <iostream>
#include <map>
using namespace std;

class Student {
public:
    explicit Student(const int no=0, const string name="", const int age=0):_no(no), _name(name), _age(age) {
        cout << "Student(int,string,age)" << endl;
    }

    Student(const Student& s) {
        cout << "Student(const Student&)" << endl;
        _no = s._no;
        _name = s._name;
        _age = s._age;
    }

    friend ostream& operator<<(ostream& os, const Student& s) {
        return os << s._no << " " << s._name << " " << s._age;
    }

private:
    int _no;
    string _name;
    int _age;
};

void show(const map<int,Student>& m) {
    for(const auto& x : m) {
        cout << x.second << endl;
    }
}

int main() {
    map<int, Student> m;
    // emplace无论键是否存在都会构造新元素。如果键已存在，新构造的元素会被立即销毁，这导致不必要的构造和析构操作
    m.emplace(1000, Student(1000, "Alice", 60));
    cout << m.size() << endl;

    // try_emplace会先检查键是否存在，如果存在则不进行任何操作，如果不存在则插入元素，这样可以避免不必要的构造和析构操作
    // 用给的值直接在对应的内存中构造
    m.try_emplace(1001, 1001, "Bob", 70);

    // 先构造一个Student对象再拷贝到对应的内存中
    m.try_emplace(1002, Student{1002, "Charlie", 80});
    show(m);

    cout << m.size() << endl;
    m.erase(1001);
    cout << m.size() << endl;
    m.erase(m.begin());
    cout << m.size() << endl;

    show(m);

    return 0;
}
