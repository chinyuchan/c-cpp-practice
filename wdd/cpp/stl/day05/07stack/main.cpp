#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <forward_list>
#include <stack>
using namespace std;


int main()
{
    stack<int> s; // deque
    s.push(10);
    cout << s.top() << endl;
    s.pop();
    cout << s.size() << endl;

    stack<int, list<int>> s1;
    s1.push(20);
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.size() << endl;

    stack<int, vector<int>> s2;
    s2.push(30);
    cout << s2.top() << endl;
    s2.pop();
    cout << s2.size() << endl;

    stack<int, forward_list<int>> s3;
    // s3.push(40); // 需要用forward_list中的push_back，但是它没有
    // s3.top();
    // s3.pop();


    return 0;
}
