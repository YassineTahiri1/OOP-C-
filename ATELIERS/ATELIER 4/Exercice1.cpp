/*EXERCICE 1 : GESTION D’UNE MÉDIATHÈQUE
On souhaite concevoir une application C++ pour gérer une médiathèque contenant plusieurs types de
ressources : Livres, Magazines et Vidéos.
1. Créer une classe de base Ressource avec des attributs communs (id, titre, auteur, annee) et des
méthodes afficherInfos() et telecharger().
2. Créer les classes dérivées Livre, Magazine et Video héritant de Ressource, chacune ajoutant
un attribut spécifique et redéfinissant afficherInfos() et telecharger().
3. Créer une classe Telechargeable contenant une méthode telecharger() et afficherMessage().
Les classes Livre, Magazine et Video héritent également de Telechargeable (héritage
multiple).
4. Créer une classe Mediatheque permettant d’ajouter, d’afficher et de rechercher des
ressources. Implémenter la surcharge de la méthode rechercher() (par titre, année, auteur +
année).
5. Dans Ressource, surcharger l’opérateur == pour comparer deux ressources selon leur
identifiant.
6. Dans main(), créer plusieurs objets, tester les méthodes afficherInfos(), telecharger() (avec
qualification de classes en cas de conflit), et comparer deux ressources.
*/
#include <iostream>
#include <vector>
using namespace std;

class Telechargeable {
public:
    virtual void telecharger() {
        cout << "Telechargement en cours..." << endl;
    }

    void afficherMessage() {
        cout << "Cette ressource est telechargeable." << endl;
    }
};

class Ressource {
protected:
    int id;
    string titre;
    string auteur;
    int annee;

public:
    Ressource(int i, string t, string a, int an) {
        id = i;
        titre = t;
        auteur = a;
        annee = an;
    }

    virtual void afficherInfos() {
        cout << "ID: " << id << endl;
        cout << "Titre: " << titre << endl;
        cout << "Auteur: " << auteur << endl;
        cout << "Annee: " << annee << endl;
    }

    virtual void telecharger() {
        cout << "Lien de telechargement pour \"" << titre << "\" :" << endl;
    }

    bool operator==(const Ressource& autre) const {
        return this->id == autre.id;
    }

    string getTitre() {
        return titre;
    }
    int getid() {
        return id;
    }
    string getauteur() {
        return auteur;
    }
    int getannee() {
        return annee;
    }
};

class Livre : public Ressource, public Telechargeable {
private:
    int isbn;

public:
    Livre(int is, int i, string t, string a, int an)
        : Ressource(i, t, a, an) {
        isbn = is;
    }

    void afficherInfos() override {
        Ressource::afficherInfos();
        cout << "ISBN: " << isbn << endl;
    }

    void telecharger() override {
        cout << "Lien de telechargement du livre \"" << titre << "\" :" << endl;
    }
};

class Magazine : public Ressource, public Telechargeable {
private:
    int numero;

public:
    Magazine(int num, int i, string t, string a, int an)
        : Ressource(i, t, a, an) {
        numero = num;
    }

    void afficherInfos() override {
        Ressource::afficherInfos();
        cout << "Numero du magazine: " << numero << endl;
    }

    void telecharger() override {
        cout << "Lien de telechargement du magazine \"" << titre << "\" :" << endl;
    }
};

class Video : public Ressource, public Telechargeable {
private:
    double duree;

public:
    Video(double d, int i, string t, string a, int an)
        : Ressource(i, t, a, an) {
        duree = d;
    }

    void afficherInfos() override {
        Ressource::afficherInfos();
        cout << "Duree de la video: " << duree << " minutes" << endl;
    }

    void telecharger() override {
        cout << "Lien de telechargement de la video \"" << titre << "\" :" << endl;
    }
};

class Mediatheque {
private:
    vector<Ressource*> Tab;

public:
    void Ajouter(Ressource* R) {
        Tab.push_back(R);
    }

    void affichage() {
        for (auto i : Tab) {
            i->afficherInfos();
            cout << "---------------------" << endl;
        }
    }

    int Rechercher(string titre) {
        for (auto i : Tab) {
            if (titre == i->getTitre()) {
                i->afficherInfos();
                return 1;
            }
        }
        cout << "Ressource introuvable !" << endl;
        return 0;
    }

    int Rechercher(int annee) {
        for (auto i : Tab) {
            if (annee == i->getannee()) {
                i->afficherInfos();
                return 1;
            }
        }
        cout << "Aucune ressource trouvée pour l'année " << annee << " !" << endl;
        return 0;
    }

    int Rechercher(string auteur, int annee) {
        for (auto i : Tab) {
            if (auteur == i->getauteur() && annee == i->getannee()) {
                i->afficherInfos();
                return 1;
            }
        }
        cout << "Aucune ressource trouvée pour " << auteur << " en " << annee << " !" << endl;
        return 0;
    }
};

int main() {
    Livre l1(978207, 1, "Les Misérables", "Victor Hugo", 1862);
    Livre l2(978014, 2, "1984", "George Orwell", 1949);
    Magazine m1(52, 3, "National Geographic", "Rédaction NG", 2023);
    Video v1(148.0, 4, "Inception", "Christopher Nolan", 2010);

    Mediatheque med;
    med.Ajouter(&l1);
    med.Ajouter(&l2);
    med.Ajouter(&m1);
    med.Ajouter(&v1);

    cout << "=== AFFICHAGE DE TOUTES LES RESSOURCES ===" << endl;
    med.affichage();

    cout << "=== RECHERCHE PAR TITRE ===" << endl;
    med.Rechercher("1984");

    cout << "=== RECHERCHE PAR ANNEE ===" << endl;
    med.Rechercher(2010);

    cout << "=== RECHERCHE PAR AUTEUR + ANNEE ===" << endl;
    med.Rechercher("Victor Hugo", 1862);

    cout << "=== TEST TELECHARGEMENT ET MESSAGE ===" << endl;
    l1.telecharger();
    l1.afficherMessage();
    v1.telecharger();
    v1.afficherMessage();

    cout << "=== TEST COMPARAISON ===" << endl;
    if (l1 == l2)
        cout << "Les ressources sont égales." << endl;
    else
        cout << "Les ressources sont différentes." << endl;

    return 0;
}
      
