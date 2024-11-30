#include <float.h>
#include <iostream>
#include <vector>
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

int main()
{
    vector<Employee> v1;
    v1.reserve(10); // 分配原始的内存，但不构造对象
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;
    cout << "-----------------------------------------" << endl;
    // 先根据参数构造1次，再拷贝构造10次
    vector<Employee> v2(10, Employee{1001, "Jack", 8000});
    cout << "v2 size: " << v2.size() << endl;
    cout << "v2 capacity: " << v2.capacity() << endl;
    cout << "-----------------------------------------" << endl;
    // 通过无参构造10个
    vector<Employee> v3(10);
    cout << "v3 size: " << v3.size() << endl;
    cout << "v3 capacity: " << v3.capacity() << endl;
    cout << "-----------------------------------------" << endl;
    // 拷贝11次，扩容需要把原来所有的对象拷贝到新的内存中
    v3.push_back(Employee{1002, "Tom", 9000});
    // 在end之前插入
    // 拷贝2次：先构造一个对象，在拷贝构造一次
    v3.insert(v3.end(), Employee{1314, "Alice", 8888});
    // 插入到begin+2的位置，相当于begin之后所有元素都后移
    // 拷贝1次：构造对象时，直接就写入内存
    v3.emplace(v3.begin()+2, 9527, "cdd", 15000);
    cout << "v3 size: " << v3.size() << endl;
    cout << "v3 capacity: " << v3.capacity() << endl;
    cout << "-----------------------------------------" << endl;
    v3.reserve(15);
    cout << "v3 size: " << v3.size() << endl;
    cout << "v3 capacity: " << v3.capacity() << endl;
    cout << "-----------------------------------------" << endl;
    // 内存足够的情况下，增多4个，调用4次无参构造
    v3.resize(15);
    cout << "v3 size: " << v3.size() << endl;
    cout << "v3 capacity: " << v3.capacity() << endl;
    cout << "-----------------------------------------" << endl;
    // 增多时，内存不够则扩容，对于原来有的对象进行拷贝构造，对新的对象则进行无参构造
    v3.resize(21, Employee{9999, "Admin", 1}); // 增加时，指定拷贝构造的对象
    cout << "v3 size: " << v3.size() << endl;
    cout << "v3 capacity: " << v3.capacity() << endl;
    cout << "-----------------------------------------" << endl;
    for (const Employee& e : v3) {
        cout << e << endl;
    }
    cout << "-----------------------------------------" << endl;
    // 释放多余的内存空间
    v3.shrink_to_fit();
    cout << "v3 size: " << v3.size() << endl;
    cout << "v3 capacity: " << v3.capacity() << endl;
    cout << "-----------------------------------------" << endl;
    // 减少时，内存容量不变，被减少的元素进行析构
    v3.resize(10);
    cout << "v3 size: " << v3.size() << endl;
    cout << "v3 capacity: " << v3.capacity() << endl;
    cout << "-----------------------------------------" << endl;
    auto it = v3.begin();
    it += 4; // 随机迭代
    cout << *it << endl;
    it -= 1;
    cout << *it << endl;
    cout << "-----------------------------------------" << endl;
    vector<int> v4{1, 2, 3, 4, 5, 6, 7, 8, 9};
    erase_if(v4, [](int x) { return x % 2 == 0; }); // C++20
    for(auto const& x: v4) {
        cout << x << " ";
    }
    cout << endl;
    cout << "-----------------------------------------" << endl;
    return 0;
}
