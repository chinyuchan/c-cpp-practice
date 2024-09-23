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
    string name;
    float salary;
};

int main() {
    Emp e1 = {};
    Employee e2 = {};

    fstream fs("emp.dat", ios::in);
    if (!fs) {
        cout << "open failed" << endl;
        return -1;
    }
    fs.read((char*)&e1, sizeof(e1));
    cout << e1.no << " " << e1.name << " " << e1.salary << endl;
    fs.read((char*)&e2, sizeof(e2));
    cout << e2.no << " " << e2.name << " " << e2.salary << endl;

    fs.close();

    return 0;
}
