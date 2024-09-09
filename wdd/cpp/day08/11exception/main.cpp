#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception {
public:
    explicit MyException(string err="my_exception") : _err(err) {}

    const char* what() const noexcept override {
        return _err.c_str();
    }
private:
    string _err;
};

void run() {
    cout << "start run" << endl;
    throw MyException("run error");
    cout << "end run" << endl;
}

int main()
{
    try {
        run();
    }
    catch(const MyException& e) {
        cout << e.what() << endl;
    }


    return 0;
}
