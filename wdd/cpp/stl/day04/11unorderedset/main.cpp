#include <iostream>
#include <unordered_set>
using namespace std;

class Student {
public:
    explicit Student(const int no=0, const string name="", const int age=0) : _no(no), _name(name), _age(age) {}

    int no() const { return _no; }
    int operator()() const { return _no; }
    // 同一个桶中的元素需要比较
    bool operator==(const Student &other) const {
        return _no == other._no;
    }
private:
    int _no;
    string _name;
    int _age;
};

class HashStudent {
public:
    int operator()(const Student &s) const {
        return s.no();
    }
};

class CompareStudent {
public:
    bool operator()(const Student &s1, const Student &s2) const {
        return s1.no() == s2.no();
    }
};

template<>
struct std::hash<Student> {
    int operator()(const Student &s) const {
        return s.no();
    }
};

template<>
struct std::equal_to<Student> {
    bool operator()(const Student &s1, const Student &s2) const {
        return s1.no() == s2.no();
    }
};

int main() {
    // 实际不会和给定的一致，
    // 如果给的值为质数，则用给定的值
    // 否则会设置一个与给定的值相差最小的质数
    unordered_set<int> s(10);
    cout << s.bucket_count() << endl;

    int arr[] = {1, 2, 3, 4, 5, 6};
    unordered_set<int> s1(&arr[0], &arr[6]);
    cout << s1.bucket_count() << endl;

    // HashStudent是让Student能转成int类型，因为需要计算每个元素在哪个桶是通过对整数求余
    // unordered_set<Student, HashStudent> students;
    // unordered_set<Student> students;
    // unordered_set<Student, hash<Student>, equal_to<Student>> students;
    // unordered_set<Student,HashStudent, CompareStudent> students;
    unordered_set<Student> students;
    students.insert(Student{1000, "Alice", 18});


    return 0;
}
