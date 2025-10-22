/*Exercice 6 
Écrire une fonction nommée incrementer() permettant d’incrémenter la valeur d’une variable passée en 
paramètre et une fonction nommée permuter() permettant d’échanger les contenus de 2 variables de 
type int fournies en argument : 
1. en transmettant l’adresse des variables concernées (seule méthode utilisable en C) ; 
2. en utilisant la transmission par référence. 
Dans les deux cas, écrire un programme (main) qui teste les deux fonctions. */

#include <iostream>
#include <cmath>
using namespace std ;

int incrementer(int *x){
    return *x = *x + 1 ;
}
void permuter(int *x , int *y){
    int v = *x ;
    *x = *y ;
    *y = v ;
    cout << "x = " << *x << endl  ;
    cout << "y = " << *y ;
}
int main (){
    int x , y , i ;
    cout << "entrer x :" ;
    cin >> x ;
    cout << "entrer y :" ;
    cin >> y ;
    
    cout << "entrer la valeurs i :" ;
    cin >>i ;


    cout << incrementer(&i) << endl ; 


    permuter( &x , &y ) ; 

}
/*int incrementer(int &x){
    return x = x + 1 ;
}
void permuter(int &x , int &y){
    int v = x ;
    x = y ;
    y = v ;
    cout << "x = " << x << endl  ;
    cout << "y = " << y ;
}
int main (){
    int x , y , i ;
    cout << "entrer x :" ;
    cin >> x ;
    cout << "entrer y :" ;
    cin >> y ;
    
    cout << "entrer la valeurs i :" ;
    cin >>i ;


    cout << incrementer(i) << endl ; 


    permuter( x , y ) ; 

}*/