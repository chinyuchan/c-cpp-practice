#include <iostream>
using namespace std;


class A {
public:
    A(int x=0) : x(x) {
        cout << "A()" << endl;
    }
    ~A() {
        cout << "~A()" << endl;
    }
    friend ostream& operator<<(ostream& os, const A& a) {
        return os << a.x;
    }
    void show() const { cout << x << endl; }
private:
    int x;
};

class PA {
public:
    PA(const A& a) : pa(new A(a)) {}
    PA(A* p) : pa(p) {}

    ~PA() {
        if (pa) {
            delete pa;
            pa = nullptr;
        }
    }

    PA(const PA& other) {
        pa = new A(*other.pa);
    }

    PA& operator=(const PA& other) {
        if (this != &other) {
            PA tmp(other);
            swap(tmp.pa, pa);
        }
        return *this;
    }

    PA(PA&& other)  noexcept {
        pa = other.pa;
        other.pa = nullptr;
    }

    PA& operator==(PA&& other) {
        if (this != &other) {
            delete pa;
            pa = other.pa;
            other.pa = nullptr;
        }
        return *this;
    }

    A& operator*() { return *pa; }
    const A& operator*() const { return *pa; }
    A* operator->() { return pa; }
    const A* operator->() const { return pa; }

private:
    A* pa;
};


int main()
{
    PA pa1(A(10));
    PA pa2(new A(1024));

    (*pa1).show();
    (*pa2).show();
    pa1->show();
    pa2->show();


    return 0;
}
