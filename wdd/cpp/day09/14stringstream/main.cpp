#include <iostream>
#include <sstream>
using namespace std;

int main() {
    istringstream iss("1234 3.14 hello world");
    int num;
    double d;
    string s1, s2;
    iss >> num >> d >> s1 >> s2;
    cout << num << " " << d << " " << s1 << " " << s2 << endl;

    // ostringstream oss("thanks"); // 会清空原来的数据
    ostringstream oss("thanks", ios::app); // 追加
    cout << oss.str() << endl;
    oss << " everyone ";
    cout << oss.str() << endl;
    oss << 1234 << " " << 5.67;
    cout << oss.str() << endl;


    return 0;
}
