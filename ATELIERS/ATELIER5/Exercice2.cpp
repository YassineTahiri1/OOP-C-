#include <iostream>
#include <exception>
using namespace std;

class Test : public exception {
public:
    static int tableau[];

    static int division(int indice, int diviseur) {
        return tableau[indice] / diviseur;
    }

    const char* what() const throw() {
        return "Attempted to divide by zero!\n";
    }
};

int Test::tableau[] = {17, 12, 15, 38, 29, 157, 89, -22, 0, 5};

int main() {
    int x, y;
    try {
        cout << "Entrez l’indice de l’entier à diviser: " << endl;
        cin >> x;
        cout << "Entrez le diviseur: " << endl;
        cin >> y;
        if (y == 0) {
            throw Test();
        } else {
            cout << "Le résultat de la division est: " << endl;
            cout << Test::division(x, y) << endl;
        }
    }
    catch (Test& e) {
        cout << e.what();
    }
    return 0;
}
