#include <iostream>
#include <vector>
using namespace std;


class Student {
public:
    explicit Student(int no=0, string name="", int score=0) : _no(no), _name(name), _score(score) {}
    void set_no(int no) { _no = no; }
    int no() const { return _no; }

    // Student(Student& s) = delete;
    // Student& operator=(Student& s) = delete;
private:
    int _no;
    string _name;
    int _score;
};

int main()
{
    Student s{1001, "Hello", 60};
    vector<Student> v;
    // 放入容器的对象是副本，放入容器的类型必须支持拷贝构造和拷贝赋值
    v.push_back(s);
    s.set_no(1002);
    cout << v.front().no() << endl;

    return 0;
}
