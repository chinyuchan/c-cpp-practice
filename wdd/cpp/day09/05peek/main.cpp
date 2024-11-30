#include <iostream>
using namespace std;

int main() {
    // 将x放到缓冲区
    cin.putback('x');
    // 查看缓冲区当前的字符
    char ch = cin.peek();
    cout << ch << endl;

    ch = cin.get();
    cout << ch << endl;

    // 将读取的字符放回缓冲区
    cin.unget();
    ch = cin.get();
    cout << ch << endl;

    return 0;
}
