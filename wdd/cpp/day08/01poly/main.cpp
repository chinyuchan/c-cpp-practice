#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual void show() const = 0;
    virtual ~Shape() { cout << "~Shape()" << endl; }
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : _width(width), _height(height) {}
    // override关键字只能用于成员函数，包括析构函数
    ~Rectangle() override {
        cout << "~Rectangle()" << endl;
    }
    double area() const override {
        return _width * _height;
    }
    void show() const override {
        cout << "Rectangle: " << _width << " " << _height << endl;
    }

private:
    double _width;
    double _height;
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : _radius(radius) {}
    ~Circle() override {
        cout << "~Circle()" << endl;
    }
    double area() const override {
        return 3.14 * _radius * _radius;
    }
    void show() const override {
        cout << "Circle: " << _radius << endl;
    }

private:
    double _radius;
};

class RightTriangle : public Shape {
public:
    RightTriangle(double bottom, double height) : _bottom(bottom), _height(height) {}
    ~RightTriangle() override {
        cout << "~RightTriangle()" << endl;
    }
    double area() const override {
        return 0.5 * _bottom * _height;
    }
    void show() const override {
        cout << "Circle: " << _bottom << " " << _height << endl;
    }

private:
    double _bottom;
    double _height;
};

Shape* max_area(Shape* shape[], size_t len) {
    int max = 0;
    for (int i = 1; i < len; i++) {
        if (shape[i]->area() > shape[max]->area()) {
            max = i;
        }
    }
    return shape[max];
}


int main()
{
    Shape* ps[] = {
        new Rectangle(1,2),
        new Circle(2),
        new RightTriangle(3, 4)
    };

    for(auto p: ps) {
        // typeid获得一个变量的类型：多态时，才能求出指针或引用的目标的类型
        cout << typeid(*p).name() << ": " << p->area() << endl;
    }
    cout << "-----------------------------------------" << endl;
    Shape* pmax = max_area(ps, 3);
    cout << "max area: " << pmax->area() << endl;
    cout << "-----------------------------------------" << endl;
    for (auto p: ps) {
        delete p;
    }

    return 0;
}
