/*Exercice 8  
Vous devez concevoir une classe appelée Voiture qui représente les caractéristiques d'une voiture et ses 
comportements associés. La classe doit inclure les éléments suivants :  
 
Attributs :  
1. marque (de type std::string) : la marque de la voiture.  
2. modele (de type std::string) : le modèle de la voiture.  
3. annee (de type int) : l'année de fabrication de la voiture.  
4. kilometrage (de type float) : le kilométrage actuel de la voiture.  
5. vitesse (de type float) : la vitesse actuelle de la voiture.  
 
Méthodes :  
1. Constructeur par défaut : Initialise tous les attributs avec des valeurs par défaut.  
2. Constructeur avec paramètres : Permet d'initialiser la voiture avec une marque, un modèle, une 
année, un kilométrage et une vitesse initiale.  
3. Méthode accelerer(float valeur) : Incrémente la vitesse actuelle de la voiture en fonction de la 
valeur passée en paramètre.  
4. Méthode freiner(float valeur) : Diminue la vitesse actuelle de la voiture en fonction de la valeur 
passée en paramètre, sans que la vitesse ne devienne négative.  
5. Méthode afficherInfo() : Affiche les informations sur la voiture (marque, modèle, année, 
kilométrage, vitesse).  
6. Méthode avancer(float distance) : Incrémente le kilométrage en fonction de la distance passée 
en paramètre.  
7. Destructeur : Affiche un message indiquant que la voiture est détruite.*/

#include <iostream>
using namespace std ;

class voiture {
    private: 
        string marque ;
        string modele ;
        int annee ;
        float kilometrage ;
        float vitesse ;
    public:
        voiture(){
            marque = "inconnue";
            modele = "inconnu";
            annee = 0;
            kilometrage = 0;
            vitesse = 0;
        }
        voiture(string m , string mo , int a , float k , float v){
            marque = m ;
            modele = mo ;
            annee = a ;
            kilometrage = k ;
            vitesse = v ;
        }

        void accelerer (float x){
         vitesse += x ;
        cout << "votre nouvelle vitesse est :" << vitesse ;
}
        void freiner (float x){
        if (vitesse>0)
        {
            vitesse -= x ;
            cout << "votre nouvelle vitesse est :" << vitesse ;
        }
}
        void afficherinfo(){
    cout << "les informations de la voiture :: "<< endl ;
    cout << "marque :" << marque << endl ;
    cout << "modele :" << modele << endl ;
    cout << "annee :" << annee << endl ;
    cout << "kilometrage :" << kilometrage << endl ;
    cout << "vitesse :" << vitesse << endl ;
}
        void distance (float x){
            kilometrage += x ;
            cout << "votre nouvelle kilometrage est :" << kilometrage ;
}    
~voiture(){
    cout << "la voiture est detruite " << endl ;
}  
};
int main(){
    voiture v1("BMW" , "M3" , 2024 , 63000 , 300 );
    v1.accelerer(40);
    v1.distance(7000);
    v1.freiner(10);
    v1.afficherinfo();


}