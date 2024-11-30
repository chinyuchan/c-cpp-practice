#include <iostream>
#include <fstream>
using namespace std;

void copy(const string& src, const string& dest) {
    ifstream ifs(src.c_str());
    if (!ifs) {
        throw string(src + " could not be opened");
    }

    ofstream ofs(dest.c_str());
    if (!ofs) {
        throw string(dest + " could not be opened");
    }

    while (!ifs.eof()) {
        char ch = ifs.get();
        if (!ifs.eof()) {
            ofs.put(ch);
        }
    }

    ifs.close();
    ofs.close();
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
        return -1;
    }

    copy(argv[1], argv[2]);

    return 0;
}
