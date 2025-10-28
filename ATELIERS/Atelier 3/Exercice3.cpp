/*Exercice 3
Créez une classe liste simplement chaînée, avec une classe liste. Cette classe a un pointeur sur
le premier élément de la liste. Elle a une méthode pour ajouter ou supprimer un élément au
début de la liste et une pour afficher la liste en entier.
Evitez toute fuite mémoire. Les éléments de la liste seront contenus dans la structure element.*/
#include <iostream>
using namespace std;

class Liste {
private:
    int valeur;       
    Liste* suivant;   
    Liste* tete;      

public:
    Liste(int v) {  // CREER UN NOEUD
        valeur = v;
        suivant = nullptr;
        tete = nullptr; 
    }

    Liste() {   // CREER UN LISTE VIDE 
        tete = nullptr;
        suivant = nullptr;
    }

    void ajouter(int val) {
        Liste* nouveau = new Liste(val); 
        nouveau->suivant = tete;         
        tete = nouveau;                  
    }

    void supprimer() {
        if (tete == nullptr) {
            cout << "La liste est vide." << endl;
            return;
        }
        Liste* tmp = tete;
        tete = tete->suivant;
        delete tmp;
    }

    void afficher() const {
        if (tete == nullptr) {
            cout << "La liste est vide." << endl;
            return;
        }

        Liste* courant = tete;
        while (courant != nullptr) {
            cout << courant->valeur << " ";
            courant = courant->suivant;
        }
        cout << endl;
    }

    ~Liste() {
        while (tete != nullptr) {
            supprimer();
        }
    }
};

int main() {
    Liste L;
    L.ajouter(77);
    L.ajouter(76);
    L.ajouter(78);
    L.ajouter(79);
    L.supprimer();
    L.afficher();
    return 0;
}
