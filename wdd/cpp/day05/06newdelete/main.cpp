#include <iostream>
using namespace std;

class Book {
public:
    explicit Book(int no=0, const string& name="", const string& author="")
        : no(no), name(name), author(author) {
        cout << "Book()" << endl;
    }

    ~Book() {
        cout << "~Book()" << endl;
    }

    void* operator new(size_t size) {
        cout << "operator new(), " << size << endl;
        void* pb = malloc(size);
        return pb;
    }

    void* operator new[](size_t size) {
        cout << "operator new[], " << size << endl;
        void* pb = malloc(size);
        return pb;
    }

    void operator delete(void *pb) {
        cout << "operator delete" << endl;
        free(pb);
    }

    void operator delete[](void *pb) {
        cout << "operator delete []" << endl;
        free(pb);
    }

    friend ostream& operator<<(ostream& os, const Book& b) {
        return os << b.no << ' ' << b.name << ' ' << b.author;
    }

private:
    int no;
    string name;
    string author;
};

// new：先分配内存，再调用构造函数
// delete：先调用对象的析构函数，‌然后再释放对象占用的内存

int main() {
    Book* pb = new Book(1001, "C++", "本贾尼·斯特劳斯特卢普");
    cout << *pb << endl;
    delete pb;
    cout << "-------------------------------" << endl;
    Book* pb2 = new Book[3];
    delete[] pb2;


    return 0;
}
