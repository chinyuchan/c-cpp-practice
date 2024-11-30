#include <algorithm>
#include <iostream>
#include <vector>//线性表
#include <set>//红黑树
using namespace std;

class Student {
public:
    explicit Student(int no = 0, string name = "", int score = 0) : no(no), name(name), score(score) {}

    bool operator<(const Student& s) const { return no < s.no; }
    bool operator<=(const Student& s) const { return no <= s.no; }
    bool operator>(const Student& s) const { return no > s.no; }
    bool operator>=(const Student& s) const { return no >= s.no; }
    bool operator==(const Student& s) const { return no == s.no && name == s.name && score == s.score; }
    bool operator!=(const Student& s) const { return !operator==(s);/*return !(*this == s);*/ }

    friend ostream& operator<<(ostream& os, const Student s) {
        return os << s.no << ' ' << s.name << ' ' << s.score;
    }

private:
    int no;
    string name;
    int score;
};

int main() {
    vector<Student> students;
    students.push_back(Student(1001, "bdd", 99));
    students.push_back(Student(1003, "add", 88));
    students.push_back(Student(1002, "cdd", 100));
    // 排序需要比较
    sort(students.begin(), students.end());
    for (const Student& s : students) {
        cout << s << endl;
    }

    // 插入数据需要比较
    set<Student> ss;
    ss.insert(Student(1002, "cdd", 100));

    Student s1 = Student(1001, "bdd", 99);
    Student s2 = Student(1003, "add", 88);
    Student s3 = Student(1003, "add", 88);
    cout << boolalpha << (s1 == s2) << endl;
    cout << boolalpha << (s1 != s2) << endl;
    cout << boolalpha << (s2 == s3) << endl;
    cout << boolalpha << (s2 != s3) << endl;


    return 0;
}
