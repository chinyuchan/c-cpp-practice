#include <iostream>
using namespace std;

class Bool {
public:
    explicit Bool(bool b = false) : b(b) {}
    explicit operator bool() const {
        return b;
    }
private:
    bool b;
};

int main()
{
    Bool b;
    // 调用opeartor bool()
    if (!b) { cout << "false" << endl; }
    //bool bl= b; // 没有explicit就可以
    bool bl = static_cast<bool>(b);
    cout << bl << endl;
    return 0;
}
