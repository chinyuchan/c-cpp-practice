#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream fout("output.txt", ios::out);
    if (fout) {
        cout << "open succeed" << endl;
    }
    else {
        cout << "open failed" << endl;
    }

    int a = 10;
    double d = 3.14;
    string str("hello world thank you");
    fout << a << " " << d << " " << str;


    fout.close();

    return 0;
}
