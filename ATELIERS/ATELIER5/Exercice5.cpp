/*EXERCICE 5
Créer une Template de fonction permettant de calculer le carré d’une valeur de type quelconque (le
résultat possédera le même type). Écrire un petit programme utilisant cette Template.*/
#include <iostream>
#include<math.h>
using namespace std;
template<typename X , typename C >
auto carre(X x , C c){
    return pow(x , c); 
}

int main(){
   cout << carre(2,2);
}
