/*Exercice 4 
Écrire un programme allouant dynamiquement un emplacement pour un tableau d’entiers, dont la 
taille est fournie en donnée.  
1. Utiliser ce tableau pour y placer des nombres entiers lus également en donnée.  
2. Créer ensuite dynamiquement un nouveau tableau destiné à recevoir les carrés des nombres 
contenus dans le premier. 
3. Supprimer le premier tableau, afficher les valeurs du second et supprimer le tout.*/

#include <iostream>
#include <cmath>
using namespace std ;

int main (){
    int n ;
    cout << "entrer la taille du tableau :" << endl ;
    cin >> n ;
    int *T = new int[n];
    cout << "Remplisser le tableau" << endl ;
    for (int i = 0 ; i < n ; i++){
        cin >> *(T+i) ;     
    }
    delete[] T ;
    int *c = new int[n] ;
    cout << "le carre de nombres est :" << endl ;
    for(int i = 0 ; i<n ; i++){
        *(c+i) = pow(*(T+i),2) ;
        cout << *(c+i) << endl ;
    }
}
