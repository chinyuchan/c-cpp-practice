#include <iostream>
#include <deque>
#include <list>
#include <vector>
using namespace std;

template<typename T, typename Container=deque<T>>
class Queue {
public:
    T& front() { return _c.front(); }
    const T& front() const { return _c.front(); }
    T& back() { return _c.back(); }
    const T& back() const { return _c.back(); }
    bool empty() const { return _c.empty(); }
    size_t size() const { return _c.size(); }
    void push(const T& data) { _c.push_back(data); }
    void pop() { _c.pop_front(); }
private:
    Container _c;
};

int main() {
    Queue<int, deque<int>> q1;
    Queue<int, list<int>> q2;
    for (int i = 1; i <= 10; i++) {
        q1.push(i);
        q2.push(i+10);
    }
    while (!q1.empty()) {
        cout << q1.front() << "," << q1.back() << " | " << q2.front() << "," << q2.back() << endl;
        q1.pop();
        q2.pop();
    }
    Queue<int, vector<int>> q3;
    q3.push(10);
    cout << q3.front() << "," << q3.back() << endl;
    // q3.pop(); // vector没有pop_front()

    return 0;
}
