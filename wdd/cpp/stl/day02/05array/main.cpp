#include <iostream>
#include <array>
using namespace std;

class Employee {
public:
    explicit Employee() : _no(0), _name("default"), _salary(0) {
        cout << "Employee()" << endl;
    }

    explicit Employee(const int no, const string& name, const float salary) : _no(no), _name(name), _salary(salary) {
        cout << "Employee(int,string,float)" << endl;
    }

    Employee(const Employee &e) {
        cout << "Employee(const Employee&)" << endl;
        _no = e._no;;
        _name = e._name;
        _salary = e._salary;
    }

    Employee& operator=(const Employee &e) {
        cout << "Employee& operator=(const Employee&)" << endl;
        if (this != &e) {
            _no = e._no;;
            _name = e._name;
            _salary = e._salary;
        }
        return *this;
    }
    ~Employee() {
        cout << "~Employee()" << endl;
    }

    [[nodiscard]] int no() const { return _no; }
    [[nodiscard]] string name() const { return _name; }
    [[nodiscard]] float salary() const { return _salary; }
    void set_no(const int no) { _no = no; }
    void set_name(const string& name) { _name = name; }
    void set_salary(const float salary) { _salary = salary; }

    friend ostream& operator<<(ostream& os, const Employee& e) {
        return os << e._no << " " << e._name << " " << e._salary;
    }
private:
    int _no;
    string _name;
    float _salary;
};

int main() {
    array<Employee, 5> employees;
    employees.fill(Employee{1001, "Jack", 8000});
    for (int i = 0; i < employees.size(); ++i) {
        cout << employees[i] << endl;
    }

    Employee& r = get<4, Employee, 5>(employees);
    cout << r << endl;

    return 0;
}
