#include <iostream>
using namespace std;

class vectok {
    int n;
    int* t;
public:
    vectok(int taille) {
        n = taille;
        t = new int[n];
    }

    ~vectok() {
        delete[] t;
    }

    vectok(const vectok& v) {
        n = v.n;
        t = new int[n];
        for (int i = 0; i < n; i++)
            t[i] = v.t[i];
    }

    vectok& operator=(const vectok& v) {
        if (this != &v) {
            delete[] t;
            n = v.n;
            t = new int[n];
            for (int i = 0; i < n; i++)
                t[i] = v.t[i];
        }
        return *this;
    }

    int& operator[](int i) {
        return t[i];
    }

    int taille() {
        return n;
    }
};

int main() {
    vectok v1(3);
    v1[0] = 1; v1[1] = 2; v1[2] = 3;

    vectok v2 = v1;
    vectok v3(3);
    v3 = v1;

    cout << "v1: ";
    for (int i = 0; i < v1.taille(); i++)
        cout << v1[i] << " ";

    cout << "\nv2: ";
    for (int i = 0; i < v2.taille(); i++)
        cout << v2[i] << " ";

    cout << "\nv3: ";
    for (int i = 0; i < v3.taille(); i++)
        cout << v3[i] << " ";

    cout << endl;
    return 0;
}
