#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    explicit Book(const string& name="", const string& author="", float price=0)
        :
        no(autoNo++),
        name(name),
        author(author),
        price(price)
    {

    }
    // 拷贝构造函数
    Book(const Book& book) {
        cout << "Book(const Book&)" << endl;
        no = book.no;
        name = book.name;
        author = book.author;
        price = book.price;
    }

    void show() const {
        cout << no << ' ' << name << ' ' << author << ' ' << price << endl;
    }
private:
    int no;
    string name;
    string author;
    float price;
    static int autoNo;
};
int Book::autoNo = 10000;

void foo(const Book b) {}
void bar(const Book& b) {}

Book getBook() {
    Book b("Python", "吉多·范罗苏姆", 66.6);
    return b;
}

int main() {
    Book b("C++", "本贾尼斯特劳斯特卢普", 199.9);
    b.show();

    Book b1 = b; // C风格
    b1.show();

    Book b2(b); // C++风格
    b2.show();

    cout <<"------------------------" << endl;
    foo(b);
    foo(b1);
    cout <<"------------------------" << endl;
    bar(b);
    bar(b1);
    cout <<"------------------------" << endl;

    // 容易里面放的是副本
    vector<Book> books;
    books.push_back(b);
    books.push_back(b2);
    cout << "===============================" << endl;
    // 匿名对象/临时对象，正常流程会先构造临时对象，再拷贝构造出形参对象，临时对象消亡。
    // 编译器对其进行优化，传递给形参时，不调用拷贝构造，直接把临时对象作为形参。
    foo(Book("Java","詹姆斯·高斯林", 99.99));
    cout << "===============================" << endl;
    // 按常理这里应该发生拷贝构造
    // 这里也是编译器优化，将临时对象直接作为b3
    Book b3 = getBook();
    cout << "===============================" << endl;
    return 0;
}
