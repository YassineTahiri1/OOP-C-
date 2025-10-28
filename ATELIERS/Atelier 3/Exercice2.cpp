/*Exercice 2
Imaginons une application qui traite des fichiers. Ces fichiers vont être lus en mémoire, traités
puis sauvegardés. Une fois lu en mémoire, un fichier a deux caractéristiques, une adresse à
partir de laquelle se situe le fichier et une longueur, ce qui se concrétisera par un pointeur et
une longueur en nombre d’octets.
Imaginons la classe "Fichier" avec un constructeur et un destructeur et les trois méthodes
suivantes:
• la méthode "Creation" qui va allouer un certain espace à partir du pointeur P,
• la méthode "Remplit" qui va remplir arbitrairement cet espace (ces remplissages
arbitraires sont la preuve de la bonne gestion mémoire car l’accès à une zone non
déclarée provoque une violation d’accès),
• la méthode "Affiche" qui va afficher la zone mémoire pointée par P.
Puis écrivons un programme main qui instancie notre classe par new, appelle nos trois
méthodes et détruit l’objet par delete et par un destructeur.*/
#include <iostream>
#include<vector>
using namespace std;

class Fichier {
    private:
        char *P = nullptr ;
        int longueur;
    public:
        Fichier(){
            longueur = 0 ; 
        }
        ~Fichier(){
            delete [] P ;
            cout << " Memoire libere" << endl ;
        }
        void Creation (int Taille){
            longueur = Taille;
            P = new char [longueur];
            cout << "Espace memoire de  " << longueur << "octets cree" << endl ;
        }
        void Remplit (){
            for (int i = 0 ; i < longueur ; i++ ){
                P[i] = 'A' + (i%26);
            }
        }
        void afficher(){
            for (int i = 0 ; i < longueur ; i++ ){
                 cout << P[i] ;
            }
            cout << endl ;
        }
};
int main (){
    Fichier *f = new Fichier();
    f->Creation(38);
    f->Remplit();
    f->afficher();

}

    

