#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << resetiosflags(ios_base::dec);
    cout << setiosflags(ios_base::hex | ios_base::uppercase | ios_base::showbase) << 1024 << endl;
    cout << dec;

    cout.imbue(locale("en_US.UTF-8"));
    double money = 1234.56;
    cout << put_money(money) << endl;
    cout << put_money(money, true) << endl;

    return 0;
}
