/*Exercice 5  
Ecrire un programme C++ qui : 
1. déclare un entier a; 
2. déclare une référence vers cet entier ref_a; 
3. déclare un pointeur vers cet entier p_a; 
4. affiche les variables, leurs adresses, la valeur pointée. */

#include <iostream>
#include <cmath>
using namespace std ;

int main (){
    int a = 12 ;
    int &ref = a ;
    int *p = &a ;
    cout << a << endl ;
    cout << &a << endl ;
    cout << ref << endl ;
    cout << &ref << endl ;
    cout << p << endl ;
    cout << *p << endl ;
    cout << &p << endl ;
}