/*Exercice 1
Une pile est un ensemble dynamique d’éléments où le retrait se fait d’une façon particulière.
En effet, lorsque l’on désire enlever un élément de l’ensemble, ce sera toujours le dernier inséré
qui sera retiré. Un objet pile doit répondre aux fonctions suivantes :
• Initialiser une pile (constructeur(s))
• Empiler un élément sur la pile (push)
• Dépiler un élément de la pile (pop)
Pour simplifier, nous allons supposer que les éléments à empiler sont de type int.
Le programme principale main comprend la définition d'une classe pile et un programme de
test qui crée deux piles p1 et p2, empile dessus des valeurs entières et les dépiler pour vérifier
les opérations push et pop.*/
#include <iostream>
#include<vector>
using namespace std;

class Pile {
    private:
        vector<int> liste ;
    public:
        Pile(){}
    void empiler (int D){
        liste.push_back(D);
    }    
    void depiler (){
        if (!liste.empty()){
        liste.pop_back();
        }else{
            cout << " Rien a depiler " << endl ;
        }
    }
    void afficher (){
        for (int i : liste){
              cout << i ;
        }
        cout << endl ;
    }
};

int main() {
    Pile p1, p2; 

    
    p1.empiler(5);
    p1.empiler(0);
    p1.empiler(9);
    p1.depiler();
    cout << "Pile 1 : ";
    p1.afficher();

    p2.empiler(1);
    p2.empiler(9);
    p2.empiler(3);
    p2.empiler(4);
    p2.depiler();
    cout << "Pile 2 : ";
    p2.afficher();

    return 0;

}