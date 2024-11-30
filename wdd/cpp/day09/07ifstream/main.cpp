#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream ifs;
    // ifs.open("input.txt", ios::in);
    ifs.open("input.txt");
    if (ifs.is_open()) {
        cout << "open succeed" << endl;
    }
    else {
        cout << "open failed" << endl;
    }

    // 格式化读取
    int num = 0;
    double d = 0;
    char s[100]{};
    ifs >> num >> d >> s;
    cout << num << endl;
    cout << d << endl;
    cout << s << endl;
    // ifs.get(s, 100);
    // ifs.getline(s, 100);
    ifs.read(s, 100);
    cout << s << endl;

    cout << "cur pos: " << ifs.tellg() << endl;

    ifs.clear();

    cout << "cur pos: " << ifs.tellg() << endl;
    ifs.seekg(0, ios::beg);
    cout << "cur pos: " << ifs.tellg() << endl;
    ifs.getline(s,100);
    cout << s << endl;

    ifs.close();

    return 0;
}
