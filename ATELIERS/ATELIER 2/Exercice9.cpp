/*Exercice 9 
Réaliser une classe C++ "vecteur3d" permettant de manipuler des vecteurs à 3 composantes (de type 
float). On y prévoira : 
− un constructeur, avec des valeurs par défaut (0), 
− une fonction d’affichage des 3 composantes du vecteur, sous la forme : (x, y, z) 
− une fonction permettant d’obtenir la somme de 2 vecteurs ; 
− une fonction permettant d’obtenir le produit scalaire de 2 vecteurs. 
− une fonction coincide permettant de savoir si 2 vecteurs ont mêmes composantes. 
− une fonction qui renvoie la norme du vecteur 
− une fonction nommée normax permettant d’obtenir, parmi deux vecteurs, celui qui a la plus 
grande norme. 
On prévoira trois situations : 
− le résultat est renvoyé par valeur ; 
− le résultat est renvoyé par adresse, l’argument étant également transmis par adresse. 
− le résultat est renvoyé par référence, l’argument étant également transmis par référence.*/
#include <iostream>
#include <cmath>
using namespace std;

class vecteur3d {
private:
    float x, y, z;
public:
    vecteur3d(float a = 0, float b = 0, float c = 0) {
        x = a; y = b; z = c;
    }

    void affichage() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }

    float norme() const {
        return sqrt(x * x + y * y + z * z);
    }

    static bool coincide(const vecteur3d& v1, const vecteur3d& v2) {
        return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
    }

    static vecteur3d somme(const vecteur3d& v1, const vecteur3d& v2) {
        return vecteur3d(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    }

    static float produit(const vecteur3d& v1, const vecteur3d& v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    static vecteur3d normax_valeur(vecteur3d v1, vecteur3d v2) {
        return (v1.norme() >= v2.norme()) ? v1 : v2;
    }

    static vecteur3d* normax_adresse(vecteur3d* v1, vecteur3d* v2) {
        return (v1->norme() >= v2->norme()) ? v1 : v2;
    }

    static vecteur3d& normax_reference(vecteur3d& v1, vecteur3d& v2) {
        return (v1.norme() >= v2.norme()) ? v1 : v2;
    }
};

int main() {
    vecteur3d v1(4, 5, 6), v2(2, 2, 7);

    cout << "v1 = "; v1.affichage();
    cout << "v2 = "; v2.affichage();

    vecteur3d s = vecteur3d::somme(v1, v2);
    cout << "Somme : "; s.affichage();

    cout << "Produit scalaire : " << vecteur3d::produit(v1, v2) << endl;
    cout << "v1 et v2 coincident ? " << (vecteur3d::coincide(v1, v2) ? "Oui" : "Non") << endl;

    cout << "Norme max (valeur) : "; vecteur3d::normax_valeur(v1, v2).affichage();
    cout << "Norme max (adresse) : "; vecteur3d::normax_adresse(&v1, &v2)->affichage();
    cout << "Norme max (référence) : "; vecteur3d::normax_reference(v1, v2).affichage();

    return 0;
}
