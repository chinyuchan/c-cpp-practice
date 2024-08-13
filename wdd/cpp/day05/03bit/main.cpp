#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <set>
using namespace std;

class BitSet {
public:
    BitSet(int size=8) : size(size) {
        for (int i = 0; i < size; ++i) {
            data[i] = 0;
        }
    }

    uint8_t& operator[](int index) {
        return data[index];
    }

    const uint8_t& operator[](int index) const {
        return data[index];
    }

    BitSet operator&(const BitSet& bs) {
        BitSet b(max(size, bs.size));
        int i;
        for (i = 0; i < min(size, bs.size); ++i) {
            b[i] = data[i] & bs.data[i];
        }
        for(; i < max(size, bs.size); ++i) {
            b[i] = 0;
        }

        return b;
    }

    BitSet operator|(const BitSet& bs) {
        int maxSize = max(size, bs.size);
        BitSet b(maxSize);
        int i;
        for (i = 0; i < min(size, bs.size); ++i) {
            b[i] = data[i] | bs.data[i];
        }
        for (; i < maxSize; ++i) {
            b[i] = size >= bs.size ? data[i] : bs.data[i];
        }
        return b;
    }

    BitSet operator^(const BitSet& bs) {
        int maxSize = max(size, bs.size);
        BitSet b(maxSize);
        int i;
        for (i = 0; i < min(size, bs.size); ++i) {
            b[i] = data[i] ^ bs.data[i];
        }
        for (; i < maxSize; ++i) {
            b[i] = size >= bs.size ? data[i] : bs.data[i];
        }
        return b;
    }

    BitSet operator!() {
        BitSet b(*this);
        for (int i = 0; i < size; ++i) {
            b.data[i] = !b.data[i];
        }

        return b;
    }

    BitSet operator>>(int n) {
        BitSet b(*this);
        if (n >= b.size) {
            memset(b.data, 0, b.size);
        }
        else {
            for(int i = n; i < b.size; ++i) {
                b.data[i-n] = b.data[i];
            }
            for(int i = b.size - n; i < size; ++i) {
                b.data[i] = 0;
            }
        }

        return b;
    }

    BitSet operator<<(int n) {
        BitSet b(*this);
        if (n >= b.size) {
            memset(b.data, 0, b.size);
        }
        else {
            for(int i = size - 1; i >= n; --i) {
                b[i] = b[i-n];
            }
            for (int i = 0; i < n; ++i) {
                b[i] = 0;
            }
        }

        return b;
    }

    friend ostream& operator<<(ostream& os, const BitSet& bs) {
        for (int i = bs.size - 1; i >=0; --i) {
            os << (int)bs[i];
        }
        return os;
    }

private:
    uint8_t data[1024]{};
    int size;
};

int main()
{
    /*
    int a = 8, b = 32;
    cout << (a & b) << endl;
    cout << (a | b) << endl;
    */

    srand(time(NULL));
    BitSet bs1(16);
    for (int i = 0; i < 16; ++i) {
        bs1[i] = rand()%2;
    }
    cout << std::right << bs1 << std::setw(9)<< endl;
    BitSet bs2(8);
    for (int i = 0; i < 8; ++i) {
        bs2[i] = rand()%2;
    }
    cout << bs2 << endl;

    BitSet bs3 = bs1 & bs2;
    cout << bs3 << endl;

    BitSet bs4 = bs1 | bs2;
    cout << bs4 << endl;

    BitSet bs5 = bs1 ^ bs2;
    cout << bs5 << endl;

    BitSet bs6 = !bs1;
    cout << bs6 << endl;

    return 0;
}
