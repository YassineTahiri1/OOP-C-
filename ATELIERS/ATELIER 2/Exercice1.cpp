/*Exercice 1 
Écrire une fonction, sans argument ni valeur de retour, qui se contente d’afficher, à chaque appel, le 
nombre total de fois où elle a été appelée sous la forme : appel numéro 3 */
#include <iostream>
using namespace std;

int i = 1 ;
void APPEL (){
    cout << "appel numero :" << i << endl ;
    i++ ;
}

int main(){
    APPEL();
    APPEL();
    APPEL();
    APPEL();
    APPEL();
    return 0 ;

}
