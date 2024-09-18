#include <iomanip>
#include <iostream>
using namespace std;


int main() {
    cout << setfill('*') << setw(20) << "hello" << endl;
    cout.fill('-');
    cout << setw(20) << "world" << endl;

    return 0;
}
