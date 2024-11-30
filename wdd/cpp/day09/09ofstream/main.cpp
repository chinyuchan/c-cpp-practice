#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    Student(int no, string name, int age, int scores[])
        :
        _no(no),
        _name(name),
        _age(age),
        _scores{scores[0], scores[1], scores[2]} {}

    friend ostream& operator<<(ostream& os, const Student& student) {
        return os
        << student._no << " "
        << student._name << " "
        << student._age << " "
        << student._scores[0] << " "
        << student._scores[1] << " "
        << student._scores[2];
    }

    friend istream& operator>>(istream& is, Student& student) {
        return is
        >> student._no
        >> student._name
        >> student._age
        >> student._scores[0]
        >> student._scores[1]
        >> student._scores[2];
    }

private:
    int _no;
    string _name;
    int _age;
    int _scores[3];
};

int main() {
    int scores1[3]{60,60,60};
    int scores2[3]{70,70,70};
    int scores3[3]{80,80,80};

    Student s[3] = {
        Student(1001, "Tom", 18, scores1),
        Student(1002, "Jack", 20, scores2),
        Student(1003, "Mark", 30, scores3)
    };

    //ofstream fout("student.txt", ios::out|ios::app);
    ofstream fout("student.txt", ios::out);
    if(fout) {
        cout << "write: open succeed" << endl;
    } else {
        cout << "write: open failed" << endl;
    }
    for (int i = 0; i < 3; ++i) {
        fout << s[i] << endl;
    }

    fout.close();

    ifstream fin("student.txt");
    if (fin) {
        cout << "read: open succeed" << endl;
    } else {
        cout << "read: open failed" << endl;
    }

    int scores[3] = {0,0,0};
    while(!fin.eof()) {
        // 最后有一个换行，会多读一次
        Student s(0,"",0, scores);
        fin >> s;
        if (fin) {
            cout << s << endl;
        } else { // 最后一次失败
            cout << "error" << endl;
        }
    }
    fin.close();

    return 0;
}
