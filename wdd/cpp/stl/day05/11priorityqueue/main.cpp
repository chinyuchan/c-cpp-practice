#include <iostream>
#include <queue>
using namespace std;

class Student {
public:
    explicit Student(const int no=0, const string name="", const int age=0) : _no(no), _name(name), _age(age) {}

    bool operator<(const Student &other) const {
        return _no < other._no;
    }

    friend ostream& operator<<(ostream& os, const Student& student) {
        return os << student._no << " " << student._name << " " << student._age;
    }
private:
    int _no;
    string _name;
    int _age;
};

int main() {
    priority_queue<int> pq;
    priority_queue<int, deque<int>, greater<int>> pq1;
    int arr[5]{4, 3, 1, 5, 0};
    for(int n : arr) {
        pq.push(n);
        pq1.push(n);
    }

    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    while(!pq1.empty()) {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    cout << endl;

    priority_queue<Student> pq2;
    pq2.emplace(1004, "David", 19);
    pq2.emplace(1001, "Alice", 20);
    pq2.emplace(1003, "Cindy", 18);
    pq2.emplace(1002, "Bob", 25);
    while (!pq2.empty()) {
        cout << pq2.top() << endl;
        pq2.pop();
    }

    return 0;
}
