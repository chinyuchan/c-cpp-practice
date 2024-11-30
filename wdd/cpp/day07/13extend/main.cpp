#include <iostream>
using namespace std;

class Shape {};

class Square : public Shape {
public:
    explicit Square(int a) : _a(a) {}
    void show() const {
        cout << "正方形(" << _a << ")" << endl;
    }
private:
    int _a;
};

class Rectangle : public Shape {
public:
    Rectangle(int w, int h) : _w(w), _h(h){}
    void show() const {
        cout << "正方形(" << _w << ',' << _h << ")" << endl;
    }
private:
    int _h;
    int _w;
};

class Triangle : public Shape {
public:
    explicit Triangle(int a) : _a(a) {}
    void show() const {
        cout << "三角形(" << _a << ")" << endl;
    }
private:
    int _a;
};


int main() {
    Square s(2);
    Rectangle r(1, 2);
    Triangle t(3);

    Shape* ps = new Shape[3]{s, r, t};

    return 0;
}
