#include <iostream>
#include <vector>
using namespace std;

class A {
public:
    virtual ~A(){}
};

class B : public A {

};

class C : public A {};

int main()
{
    try {
        int* p = new int[0xFFFFFFFFFF];
        B b;
        A& ra = b;
        C& rc = dynamic_cast<C&>(ra);
        vector<int> v(10);
        v.at(10);
    } catch(bad_alloc& e) {
        cout << e.what() <<endl;
    } catch(bad_cast& e) {
        cout << e.what() << endl;
    } catch(out_of_range& e) {
        cout << e.what() << endl;
    }

    cout << "try-catch end" << endl;

    return 0;
}
