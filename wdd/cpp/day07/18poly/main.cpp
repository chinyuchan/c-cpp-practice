#include <iostream>
using namespace std;

class Shape {
public:
    [[nodiscard]] virtual double area() const = 0;
};

class Square : public Shape {
public:
    explicit Square(double a) : _a(a) {}
    // 重写/覆盖父类中的虚函数
    [[nodiscard]] double area() const override { return _a * _a; }
private:
    double _a;
};

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : _w(w), _h(h) {}
    // 重写/覆盖父类中的虚函数
    [[nodiscard]] double area() const override { return _w * _h; }
private:
    double _h;
    double _w;
};

class Circle : public Shape {
public:
    explicit Circle(int r) : _r(r) {}
    // 重写/覆盖父类中的虚函数
    [[nodiscard]] double area() const override { return 3.14 * _r * _r; }
private:
    int _r;
};


int main() {
    Square s(2);
    Rectangle r(1, 2);
    Circle c(3);

    Shape* shapes[3] = {&s, &r, &c};
    for(auto s: shapes) {
        cout << s->area() << endl;
    }
    return 0;
}
