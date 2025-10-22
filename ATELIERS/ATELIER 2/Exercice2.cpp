/*Exercice 2 
Écrire 2 fonctions à un argument entier et une valeur de retour entière permettant de préciser si 
l’argument reçu est multiple de 2 (pour la première fonction) ou multiple de 3 (pour la seconde 
fonction). 
 
Utiliser ces deux fonctions dans un petit programme qui lit un nombre entier et qui précise s’il est pair, 
multiple de 3 et/ou multiple de 6, comme dans cet exemple (il y a deux exécutions) : 
 
donnez un entier : 9 
il est multiple de 3
 --------------- 
donnez un entier : 12 
il est pair 
il est multiple de 3 
il est divisible par 6 */

#include <iostream>
using namespace std;

int Multiple(int x) {
    if (x % 2 == 0)
        return 1;
    else
        return 0;
}

int multiple(int y) {
    if (y % 3 == 0)
        return 1;
    else
        return 0;
}

int main() {
    int n;
    cout << "donnez un entier : ";
    cin >> n;

    if (Multiple(n))
        cout << "il est pair" << endl;
    if (multiple(n))
        cout << "il est multiple de 3" << endl;
    if (Multiple(n) && multiple(n))
        cout << "il est divisible par 6" << endl;

    return 0;
}
