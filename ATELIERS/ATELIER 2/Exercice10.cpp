/*Exercice 10
Effectuer les opérations arithmétiques sur des nombres complexes à l'aide d'une classe et d'un objet.
Le programme doit demander la partie réelle et imaginaire de deux nombres complexes et afficher les
parties réelle et imaginaire de l’opération demandée. (égalité, addition, soustraction, multiplication,
division). Le choix de l’opération peut être fait par un Menu.*/
#include <iostream>
#include <cmath>
using namespace std;

class complexes {
    private:
        float reelle ;
        float imaginaire ;
    public:
        complexes(float r=0 , float i=0 ){
            reelle = r ;
            imaginaire = i ;
        }
        static bool egalite ( const complexes &ob1 , const complexes &ob2){
                return (ob1.reelle==ob2.reelle && ob1.imaginaire==ob2.imaginaire) ;
        }
        static complexes somme ( const complexes &ob1 , const complexes &ob2){
            complexes s(0.0 , 0.0) ;
            s.reelle = ob1.reelle + ob2.reelle ;
            s.imaginaire = ob1.imaginaire + ob2.imaginaire ;
            return s ; 
        }
        static complexes produit ( const complexes &ob1 , const complexes &ob2){
            return complexes(
            ob1.reelle * ob2.reelle - ob1.imaginaire * ob2.imaginaire,
            ob1.reelle * ob2.imaginaire + ob1.imaginaire * ob2.reelle
        );
        }
        static complexes soustraction ( const complexes &ob1 , const complexes &ob2){
            complexes s(0.0 , 0.0) ;
            s.reelle = ob1.reelle - ob2.reelle ;
            s.imaginaire = ob1.imaginaire - ob2.imaginaire ;
            return s ; 
        }
        static complexes division(const complexes& ob1, const complexes& ob2) {
             float denom = ob2.reelle * ob2.reelle + ob2.imaginaire * ob2.imaginaire;
         return complexes(
            (ob1.reelle * ob2.reelle + ob1.imaginaire * ob2.imaginaire) / denom,
            (ob1.imaginaire * ob2.reelle - ob1.reelle * ob2.imaginaire) / denom );
        }
        void affichage () const {
            cout << "(" << reelle << ", " << imaginaire << "i)" << endl;
        }
};

int main() {
    complexes c1, c2, res;
    float r1, i1, r2, i2;
    int choix;

    cout << "=== OPERATIONS SUR NOMBRES COMPLEXES ===" << endl;

    cout << "Entrez la partie reelle du premier nombre : ";
    cin >> r1;
    cout << "Entrez la partie imaginaire du premier nombre : ";
    cin >> i1;

    cout << "Entrez la partie reelle du deuxieme nombre : ";
    cin >> r2;
    cout << "Entrez la partie imaginaire du deuxieme nombre : ";
    cin >> i2;

    c1 = complexes(r1, i1);
    c2 = complexes(r2, i2);

    cout << "\n=== MENU ===" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Soustraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Egalite" << endl;
    cout << "Votre choix : ";
    cin >> choix;

    switch (choix) {
    case 1:
        res = complexes::somme(c1, c2);
        cout << "Resultat : "; res.affichage();
        break;
    case 2:
        res = complexes::soustraction(c1, c2);
        cout << "Resultat : "; res.affichage();
        break;
    case 3:
        res = complexes::produit(c1, c2);
        cout << "Resultat : "; res.affichage();
        break;
    case 4:
        res = complexes::division(c1, c2);
        cout << "Resultat : "; res.affichage();
        break;
    case 5:
        if (complexes::egalite(c1, c2))
            cout << "Les deux nombres complexes sont egaux." << endl;
        else
            cout << "Les deux nombres complexes sont differents." << endl;
        break;
    default:
        cout << "Choix invalide !" << endl;
    }

    return 0;
}