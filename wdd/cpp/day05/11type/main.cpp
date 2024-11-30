#include <iostream>
using namespace std;

class Student {
public:
    explicit Student(int no, string name="", int score=0) : _no(no), _name(name), _score(score) {}

    explicit operator int() const {
        cout << "operator int()" << endl;
        return _no;
    }

    explicit operator string() const {
        cout << "operator string()" << endl;
        return _name;
    }

private:
    int _no;
    string _name;
    int _score;
};



int main() {
    Student s(1001, "cdd", 99);

    int num = static_cast<int>(s);
    cout << num << endl;

    string str = static_cast<string>(s);
    cout << str << endl;

    return 0;
}
