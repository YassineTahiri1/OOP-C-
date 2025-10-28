/*Exercice 4
On souhaite créer un petit programme de gestion simplifiée de comptes bancaires. Chaque
compte appartient à un client et possède un solde. Le programme doit permettre de : créer des
clients et des comptes, copier des comptes, afficher les informations des comptes et des clients,
suivre le nombre total de comptes existants, calculer des intérêts sur les comptes.
1. Classe Client
Créer une classe Client contenant les attributs : un identifiant (int id), un nom (string nom), un
prénom (string prenom).
1. Définir les constructeurs nécessaires pour permettre :
o la création d’un client vide,
o la création d’un client avec des valeurs initiales,
o la copie d’un client existant.
2. Ajouter un destructeur adapté.
3. Créer une méthode pour afficher les informations d’un client.
Attention : faut-il une copie profonde ou superficielle ? Le destructeur est-il indispensable ?
2. Classe Compte
Créer une classe Compte contenant : un numéro de compte (int numero), un solde (float solde),
un pointeur vers un objet Client (Client* client), un attribut partagé entre tous les comptes
indiquant le nombre total de comptes ouverts.
1. Ajouter les constructeurs nécessaires pour initialiser correctement un compte :
o sans paramètre,
o avec paramètres (numéro, solde, client associé),
o par copie.
2. Implémenter le destructeur qui libère correctement la mémoire du client associé.
3. Créer une méthode d’affichage des informations du compte (numéro, solde, client).
4. Ajouter une variable statique pour compter le nombre total de comptes créés.
o Incrémenter ce compteur dans les constructeurs.
o Le décrémenter dans le destructeur.
5. Ajouter une méthode statique permettant d’afficher le nombre total de comptes
existants.
3. Fonction utilitaire
Créer une fonction globale calculInteret(float solde, float taux) qui retourne le solde après
application des intérêts. Décider si cette fonction doit être déclarée inline ou non. Justifier
votre choix.
4. Programme principal (main)
Dans la fonction main() :
1. Créer plusieurs clients et comptes.
2. Copier certains comptes pour tester le constructeur de copie.
3. Supprimer certains comptes et observer le comportement du destructeur.
4. Afficher à différentes étapes le nombre total de comptes.
5. Appliquer des intérêts sur certains comptes à l’aide de la fonction calculInteret().
*/
#include <iostream>
using namespace std;
class Client {
    private:
        int id ;
        string nom ;
        string prenom ;
    public:
        Client(){}
        Client(int i , string n , string p){
            id = i ;
            nom = n ;
            prenom = p ;
        }
        Client(const Client &c){
            id = c.id ;
            nom =c.nom ;
            prenom = c.prenom ;
        }
        ~Client(){}
        void afficher() const{
            cout << "Nom :" << nom << endl ;
            cout << "Prenom :" << prenom << endl ;
            cout << "Identifiant :" << id << endl ;
        }      
};

class Compte {
    private:
        int numero ;
        float solde ;
        Client *client ;
        static int attribut ;
    public:
        Compte(){
            numero = 0 ;
            solde = 0.0 ;
            client = nullptr ;
        }
        Compte(int n , float s , Client c){
            numero = n ;
            solde = s ;
            client = new Client(c) ;
            ++attribut;
            cout << attribut << endl ;
        }
        Compte(Compte &co){
            numero = co.numero ;
            solde = co.solde ;
            client = new Client(*co.client); 
            ++attribut;
        }
        ~Compte(){
            delete client ;
            --attribut;
            cout << attribut << endl ;
        }
        void display()const{
            cout << "Numero :" << numero << endl ;
            cout << "Solde :" << solde << endl ;
            client->afficher() ;
        }
        static void nbrCompte (){
              cout << "le nombre total de vos comptes est :" << attribut ;
        }
        void setsolde (float s){
            solde = s ;
        }
        float getsolde (){
            return solde ;
        }
};
inline float calculInteret(float solde, float taux) {  
            return solde + (solde * taux / 100);
}
//inline car c’est une fonction courte et simple,
// ce qui permet d’éviter le coût d’appel de fonction et d’améliorer légèrement les performances
int Compte::attribut = 0;
int main() {
    Client c1(1, "yassine", "Thr");
    Client c2(2, "cristiano", "ronaldo");
    Client c3(3, "ahmed", "Ali");

    Compte C1(101, 1200.5, c1);
    Compte C2(102, 3000, c2);
    Compte C3(103, 8000000, c3);

    Compte::nbrCompte();

    C1.display();
    C2.display();

    Compte C4(C3);
    C4.display();

    float nouveauSolde = calculInteret(C2.getsolde(), 5);
    C2.setsolde(nouveauSolde);
    cout << C2.getsolde() << endl;

    Compte::nbrCompte();

    return 0;
}
