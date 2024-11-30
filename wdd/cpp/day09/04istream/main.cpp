#include <iostream>
#include <sstream>
using namespace std;


int main()
{
    char ch = cin.get();
    cout << ch << endl;
    cin.get(ch); // 可能读到\n
    cout << ch << endl;

    char s[100]{};
    cin.get(s, 100, ' ');
    cout << s << endl;

    return 0;
}
