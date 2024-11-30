#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <queue>
using namespace std;

template<typename T, typename Container = deque<T>, typename Compare = std::less<T>>
class PriorityQueue {
public:
    T& top() { return _c.front(); }
    const T& top() const { return _c.front(); }
    bool empty() const { return _c.empty(); }
    size_t size() const { return _c.size(); }
    void push(const T& data) {
        _c.push_back(data);
        push_heap(_c.begin(), _c.end(), Compare());
    }
    void pop() {
        pop_heap(_c.begin(), _c.end(), Compare());
        _c.pop_back();
    }

private:
    Container _c;
    Compare _cmp;
};


int main() {
    PriorityQueue<int> pq;
    PriorityQueue<int, vector<int>, greater<>> pq1;
    int arr[5]{10, 23, 8, 27, 16};
    for (int n : arr) {
        pq.push(n);
        pq1.push(n);
    }
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    while (!pq1.empty()) {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    cout << endl;

    priority_queue<int, list<int>> pq2;
    // pq2.push(10); // list不支持随机访问

    return 0;
}
