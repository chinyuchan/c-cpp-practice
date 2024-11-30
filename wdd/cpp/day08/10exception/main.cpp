#include <iostream>
using namespace std;


class BaseException : public exception {
public:
    virtual string what() {
       return  "BaseException::name()";
    }
};

class DerivedException : public BaseException {
public:
    string what() override {
        return "DerivedException::name()";
    }
};

int main() {
    try {
        throw DerivedException();
    }
    catch (DerivedException& e) {
        cout << e.what() << endl;
    }
    catch (BaseException& e) {
        cout << e.what() << endl;
    }
    catch(exception& e) { // 所有C++异常的基类
        cout << e.what() << endl;
    }
    catch(...) { // 保证异常一定能被捕获
        cout << "unknown exception" << endl;
    }
    return 0;
}
