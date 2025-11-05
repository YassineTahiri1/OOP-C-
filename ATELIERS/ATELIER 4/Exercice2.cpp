/*EXERCICE 2: SYSTÈME DE GESTION BANCAIRE
Une banque souhaite développer une application en C++ pour gérer les comptes de ses clients et
permettre à certains agents autorisés d’effectuer des opérations confidentielles.
Chaque compte est associé à un client et contient des informations sensibles (numéro de compte, solde,
code secret).
1. Créer une classe Client contenant les informations de base : nom, CIN et un identifiant client.
2. Créer une classe CompteBancaire représentant un compte, avec :
o un numéro de compte,
o un solde,
o un code secret (non accessible publiquement),
o et une référence vers le client propriétaire.
3. Créer une classe AgentBancaire qui représente un employé autorisé à effectuer des opérations
confidentielles sur les comptes (consultation du code secret, transfert entre comptes, etc.).
Les méthodes d’un agent doivent pouvoir accéder à certaines informations privées des comptes
et des clients sans tout exposer au reste du programme.
4. Ajouter une classe Banque pour centraliser la gestion des clients et des comptes (ajout,
affichage, transfert, etc.). Cette classe doit pouvoir afficher les détails internes d’un compte pour
des raisons d’audit interne.
Contraintes :
• Aucune donnée sensible (comme le code secret) ne doit être directement accessible depuis
l’extérieur.
• Seules certaines classes ou fonctions internes doivent y avoir accès (à l’étudiant de concevoir la
bonne relation entre elles).
• L’accès à certaines informations devra être possible sans recourir à des accesseurs classiques
(get/set).
Dans main() :
• Créer plusieurs clients et comptes.
• Simuler des dépôts, retraits, et transferts entre comptes.
• Afficher un rapport d’audit via la classe Banque montrant les soldes et informations
confidentielles*/
#include <iostream>
#include <vector>
using namespace std;

class Client {
private:
    string nom;
    string cin;
    int id;
public:
    Client(string n, string c, int i) {
        nom = n;
        cin = c;
        id = i;
    }
    string getname() const { return nom; }
    string getcin() const { return cin; }
    int getid() const { return id; }
};

class Compte {
private:
    int code;
    float solde;
    int num;
    const Client& proprietaire;
public:
    Compte(int c, int n, float s, Client& C) 
        : proprietaire(C), code(c), solde(s), num(n) {}
    void deposer(float montant) { solde += montant; }
    bool retirer(float montant) {
        if (montant <= solde) {
            solde -= montant;
            return true;
        }
        return false;
    }
    friend class AgentBancaire;
    friend class Banque;
};

class AgentBancaire {
private:
    string nom;
public:
    AgentBancaire(string n) : nom(n) {}
    void consultersolde(Compte& C) {
        cout << "Solde: " << C.solde << endl;
    }
    void affichercode(Compte& C) {
        cout << "Code secret: " << C.code << endl;
    }
};

class Banque {
private:
    string nom;
    vector<Compte*> compte;
    vector<Client*> client;
public:
    Banque(string n) : nom(n) {}
    void ajouterClient(Client* c) { client.push_back(c); }
    void ajouterCompte(Compte* c) { compte.push_back(c); }
    void afficherAudit() {
        cout << "\n=== Rapport d'Audit Interne ===\n";
        for (auto c : compte) {
            cout << "Compte N°" << c->num
                 << " | Propriétaire : " << c->proprietaire.getname()
                 << " | Solde : " << c->solde
                 << " | Code secret : " << c->code
                 << endl;
        }
    }
    void transfert(Compte& source, Compte& cible, float montant) {
        if (source.solde >= montant) {
            cible.solde += montant;
            source.solde -= montant;
            cout << "Transfert de " << montant << " effectué.\n";
        } else {
            cout << "Solde insuffisant pour le transfert.\n";
        }
    }
};

int main() {
    Client c1("Yassine", "G35445", 73646473);
    Client c2("Ronaldo", "G3645", 1367888473);
    Client c3("Jean", "H4523", 34567873);
    Client c4("Karim", "G55649", 3775873);

    Compte C1(1111, 1001, 5000, c1);
    Compte C2(2222, 1002, 7000, c2);
    Compte C3(3333, 1003, 9000, c3);
    Compte C4(4444, 1004, 10000, c4);

    Banque b("Banque Centrale");
    b.ajouterClient(&c1);
    b.ajouterClient(&c2);
    b.ajouterClient(&c3);
    b.ajouterClient(&c4);
    b.ajouterCompte(&C1);
    b.ajouterCompte(&C2);
    b.ajouterCompte(&C3);
    b.ajouterCompte(&C4);

    C1.deposer(2000);
    C2.retirer(1500);
    b.transfert(C3, C1, 2500);

    AgentBancaire agent("Ahmed");
    agent.consultersolde(C1);
    agent.affichercode(C1);

    b.afficherAudit();
    return 0;
}
