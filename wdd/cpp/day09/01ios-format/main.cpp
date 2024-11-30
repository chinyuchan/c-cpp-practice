#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << true << ":" << false << endl;
    cout << boolalpha << true  << ":" << false << endl;
    cout << noboolalpha << endl;

    // 进制
    cout << hex << showbase << 1024 << endl;
    cout << dec << showbase << 1024 << endl;
    cout << oct << showbase << 1024 << endl;
    cout << dec << noshowbase << endl;

    cout << 123.45 << endl;
    cout << showpoint << 123.45 << endl;
    cout << noshowpoint << endl;

    // +156
    cout << showpos << 156 << endl; // 显式正号
    cout << noshowpos << endl;

    char ch;
    cin >> noskipws; // 不跳过空格字符
    cin >> ch;
    cout << "ch=" << ch << endl;
    cin >> skipws;

    // abc
    cout << uppercase << "abc" << endl; // uppercase不是将字符串输出为大写，而是将数字的前缀输出为大写
    // 0X400
    cout << hex << showbase << 1024 << endl;
    cout << dec << endl;
    // ---------------hello
    cout << setw(20) << setfill('-') << "hello" << endl; // 用'-'填充
    // hello---------------
    cout << setw(20) << left << "hello" << endl; // 左对齐
    // ---------------hello
    cout << setw(20) << right << "hello" << endl; // 右对齐（默认）
    // 00000000000000001024
    cout << setw(20) << setfill('0') << 1024 << endl;
    // 1024XXXXXXXXXXXXXXXX
    cout << setw(20) << setfill('X') << left << 1024 << endl;
    // ****************1024
    cout << setw(20) << setfill('*') << right << 1024 << endl;

    cout << scientific << 12345.6789 << endl; // 科学计数法



    return 0;
}
