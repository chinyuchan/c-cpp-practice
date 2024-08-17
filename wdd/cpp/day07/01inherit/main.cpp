#include <iostream>
using namespace std;

class Father {
public:
    explicit Father(int x = 0, int y = 0) : _x(x), _y(y) {}
    void show() const { cout << _x << ' ' << _y << endl; }
    int _x;
    int _y;
};

class Son : public Father {

};

int main()
{
    cout << sizeof(Son) << endl;
    Son s;
    cout << s._x << ' ' << s._y << endl;
    s.show();

    return 0;
}
