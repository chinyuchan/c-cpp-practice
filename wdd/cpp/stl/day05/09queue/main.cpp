#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <list>
using namespace std;


int main() {
    queue<int> q1;
    queue<int, deque<int>> q2;
    queue<int, list<int>> q3;

    for (int i = 1; i <= 10; i++) {
        q1.push(i);
        q2.push(i+10);
        q3.push(i+20);
    }
    while(!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;

    while(!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;

    while(!q3.empty()) {
        cout << q3.front() << " ";
        q3.pop();
    }
    cout << endl;

    queue<int, vector<int>> q4;
    q4.push(40);
    q4.push(41);
    q4.push(42);
    cout << q4.front() << endl;
    cout << q4.back() << endl;
    // q4.front(); // ERROR


    return 0;
}
