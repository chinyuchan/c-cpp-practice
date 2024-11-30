#include <iostream>
#include <deque>
using namespace std;


int main() {
    deque<int> dq1;
    deque<int> dq2(10);
    deque<int> dq3(10, 1);
    deque<int> dq4{1, 2, 3, 4, 5};
    deque<int> dq5{dq4};
    deque<int> dq6(dq5.begin(), dq5.end());

    cout << *(dq4.begin()+3) << endl;
    dq4.push_back(6);
    dq4.push_front(0);
    cout << "front: " << dq4.front() << endl;
    cout << "back: " << dq4.back() << endl;
    cout << "size: " << dq4.size() << endl;

    return 0;
}
