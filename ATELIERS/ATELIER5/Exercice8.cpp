#include <iostream>
#include <stdexcept>
using namespace std;

class Stack {
private:
    int *tab;
    int Taille;
    int sommet;

public:
    Stack(int T = 20) {
        Taille = T;
        tab = new int[Taille];
        sommet = 0;
    }

    Stack(const Stack &p) {
        Taille = p.Taille;
        sommet = p.sommet;
        tab = new int[Taille];
        for (int i = 0; i < sommet; i++)
            tab[i] = p.tab[i];
    }

    Stack &operator=(const Stack &) {
        throw runtime_error("Affectation interdite");
    }

    ~Stack() {
        delete[] tab;
    }

    Stack &operator<<(int n) {
        if (sommet < Taille) {
            tab[sommet] = n;
            sommet++;
        } else {
            cout << "Pile pleine" << endl;
        }
        return *this;
    }

    Stack &operator>>(int &n) {
        if (sommet == 0) {
            cout << "Pile vide" << endl;
        } else {
            sommet--;
            n = tab[sommet];
        }
        return *this;
    }

    bool operator++(int) {
        return (sommet == Taille);
    }

    bool operator--(int) {
        return (sommet == 0);
    }

    void afficher() const {
        cout << "Pile : ";
        for (int i = 0; i < sommet; i++)
            cout << tab[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack p(5);
    int x;

    p << 10 << 20 << 30;
    
    p.operator<<(200);
    p.operator<<(900);
    p.afficher();
    if (p++)
        cout << "Pile pleine" << endl;

    p >> x;
    cout << "Element retire : " << x << endl;

    if (p--)
        cout << "Pile vide" << endl;
    else
        cout << "Encore des elements" << endl;

    p.afficher();

    return 0;
}
