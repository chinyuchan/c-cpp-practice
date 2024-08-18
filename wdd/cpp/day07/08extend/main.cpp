#include <iostream>
using namespace std;

class A {
public:
    int _x;
};

class B {
public:
    long _y;
};

class C {
public:
    int _z;
};


class D : public A, public B, public C {
public:
    int _w;
};


int main() {
    cout << sizeof(D) << endl;
    D d;
    // 父类指针指向子类对象，其实是指向子类对象中的父类部分
    A* pa = &d;
    B* pb = &d;
    C* pc = &d;
    cout << "&d = " << &d << endl;
    cout << "pa = " << pa << endl;
    cout << "pb = " << pb << endl;
    cout << "pc = " << pc << endl;
    cout << "--------------------------" << endl;
    A& ra = d;
    B& rb = d;
    C& rc = d;
    cout << "&ra = " << &ra << endl;
    cout << "&rb = " << &rb << endl;
    cout << "&rc = " << &rc << endl;
    cout << "--------------------------" << endl;
    D* pd = static_cast<D*>(pb); // 会计算偏移量
    cout << "pd = " << pd << endl; // OK
    // 重解释类型转换：转换前后都是同一块内存，因此地址不会变
    pd = reinterpret_cast<D*>(pb);
    cout << "pd = " << pd << endl; // ERROR

    return 0;
}
