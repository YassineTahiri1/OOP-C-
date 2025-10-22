/*Exercice 7 
Écrire une fonction récursive en C++ qui affiche toutes les permutations possibles d’une chaîne de 
caractères donnée. Aucune bibliothèque spéciale ne doit être utilisée !!  */
#include <iostream>
using namespace std;

void permuter  (string chaine , int debut , int fin){
    if (debut == fin){
        cout << chaine << endl ;
    } else {
        for (int i=debut ; i <= fin ; i++ ){
            char temp = chaine[debut] ;
            chaine[debut] = chaine [i] ;
            chaine[i] = temp ;

            permuter (chaine , debut + 1 , fin);
             
            temp = chaine[debut] ;
            chaine[debut] = chaine [i] ;
            chaine[i] = temp ;

                 
        }

    }
}

int main (){
    char mot[20];
    cout << "Entrez un mot : ";
    cin >> mot;

    int longueur = 0;
    while (mot[longueur] != '\0') {
        longueur++;
    }

    cout << "Les permutations possibles sont :" << endl;
    permuter(mot, 0, longueur - 1);

    return 0;
}

