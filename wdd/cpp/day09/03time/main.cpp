#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;


int main() {
    time_t t = time(nullptr); // 1970-1-1 00:00:00到现在的秒数
    cout << t << endl;
    cout << ctime(&t) << endl;

    tm* pt = localtime(&t);
    char s[1024]{};
    strftime(s, 1024, "%Y-%m-%d %H:%M:%S", pt);
    cout << s << endl;

    // C++
    cout << put_time(pt, "%c %Z") << endl;
    cout.imbue(locale("en_US.UTF_8"));
    cout << put_time(pt, "%Y-%m-%d %H:%M:%S") << endl;
    return 0;
}

