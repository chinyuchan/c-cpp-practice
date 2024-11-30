#include <iostream>
#include <deque>
#include <vector>
#include <list>
using namespace std;

template<typename T, class Container = deque<T>>
class Stack {
public:
    T& top() { return _c.back(); }
    const T& top() const { return _c.back(); }
    bool empty() const { return _c.empty(); }
    size_t size() const { return _c.size(); }
    void push(const T& data) { return _c.push_back(data); }
    void pop() { return _c.pop_back(); }
private:
    Container _c;
};

int main() {
    Stack<int> s;
    for (int i = 0; i < 10; ++i) {
        s.push(i);
    }

    Stack<int> s1(s);
    Stack<int> s2;
    s2.push(10);
    s2 = s;
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    Stack<int, vector<int>> s3;
    Stack<int, list<int>> s4;
    for (int i = 0; i < 10; ++i) {
        s3.push(i+10);
        s4.push(i+20);
    }
    while(!s3.empty()) {
        cout << s3.top() << " ";
        s3.pop();
    }
    cout << endl;
    while(!s4.empty()) {
        cout << s4.top() << " ";
        s4.pop();
    }
    cout << endl;


    return 0;
}
