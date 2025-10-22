/*Exercice 3  
Écrire, de deux façons différentes, un programme qui lit 10 nombres entiers dans un tableau avant d’en 
rechercher le plus grand et le plus petit : 
 
a. en utilisant uniquement le « formalisme tableau » ; 
b. en utilisant le « formalisme pointeur », à chaque fois que cela est possible. */

#include <iostream>
using namespace std ;

int main (){
    int n ;
    cout << "entrer la taille du tableau :" << endl ;
    cin >> n ;
    int* T = new int[n];
    cout << "Remplisser le tableau" << endl ;
    for (int i = 0 ; i < n ; i++){
        cin >> *(T+i) ;     
    }
    int *max = T ;
    for (int i=1 ; i< n ; i++){
        if ( *(T+i) > *max ){
           max = T+i ;
        }
    }
    int *min = T ;
    for (int i=1 ; i< n ; i++){
        if ( *(T+i) < *min ){
           min = T+i ;
        }
    }
    cout  << "le max est :" << *max << endl ;
    cout  << "le min est :" << *min << endl ;
 
}

// int main() {
//     int n;
//     cout << "Entrer la taille du tableau : ";
//     cin >> n;

//     int T[n];

//     cout << "Remplissez le tableau :" << endl;
//     for (int i = 0; i < n; i++) {
//         cin >> T[i];
//     }

//     int max = T[0];
//     int min = T[0];

//     for (int i = 1; i < n; i++) {
//         if (T[i] > max) 
            //max = T[i];
//         if (T[i] < min) 
            //min = T[i];
//     }

//     cout << "Le maximum est : " << max << endl;
//     cout << "Le minimum est : " << min << endl;
// }
