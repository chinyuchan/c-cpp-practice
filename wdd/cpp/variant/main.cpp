#include <iostream>
#include <variant>
using namespace std;

// variant
// 更安全的union，存储多个不同类型的值

struct MyVisitor {
    void operator()(char c) const { cout << c << endl; }
    void operator()(int i) const { cout << i << endl; }
    void operator()(double d) const { cout << d << endl; }
    void operator()(bool b) const { cout << boolalpha << b << endl; }
};

void print_var(variant<int, double, bool, char> const& var) {
    if (holds_alternative<int>(var)) {
        cout << get<int>(var) << endl;
    }
    else if(holds_alternative<double>(var)) {
        cout << get<double>(var) << endl;
    }
    else if(holds_alternative<bool>(var)) {
        cout << boolalpha << get<bool>(var) << endl;
    }
    else {
        cout << get<char>(var) << endl;
    }
}

void print_var2(variant<int, double, bool, char> const& var) {
    if (var.index() == 0) {
        cout << get<int>(var) << endl;
    }
    else if(var.index() == 1) {
        cout << get<double>(var) << endl;
    }
    else if(var.index() == 2) {
        cout << boolalpha << get<bool>(var) << endl;
    }
    else {
        cout << get<char>(var) << endl;
    }
}

int main() {
    variant<int, double, bool, char> var = 'A';
    cout << get<char>(var) << endl;
    cout << get<3>(var) << endl;
    cout << "-----------------------------------------------" << endl;
    try {
        // 没有存int类型的值，会出异常
        cout << get<int>(var) << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
    cout << "-----------------------------------------------" << endl;
    var = 100;
    print_var(var);
    var = true;
    print_var2(var);
    cout << "-----------------------------------------------" << endl;
    visit([](auto arg) { cout << arg << endl; }, var);

    visit(MyVisitor{}, var);
    var = 1.23;
    visit(MyVisitor{}, var);
    var = true;
    visit(MyVisitor{}, var);
    var = 1024;
    visit(MyVisitor{}, var);



    return 0;
}
