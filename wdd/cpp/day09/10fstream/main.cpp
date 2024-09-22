#include <iostream>
#include <fstream>
using namespace std;

struct Emp {
    int no;
    char name[32];
    float salary;
};

class Employee {
public:
    int no;
    string name; // string写到文件中是一个内存地址
    float salary;
};

int main() {
    Emp e1 = {110, "Jack", 4000};
    Employee e2 = {110, "Jack", 4000};

    fstream fs("emp.dat", ios::in | ios::out | ios::trunc);
    if (!fs) {
        cout << "open failed" << endl;
        return -1;
    }
    fs.write((char*)&e1, sizeof(e1));
    fs.write((char*)&e2, sizeof(e2));

    fs.close();

    return 0;
}
