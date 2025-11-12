/*EXERCICE 1
1. Créer un set paramètre pour le type int que vous remplirez avec tous les entiers de 1 a 100.
2. Écrire une fonction de recherche qui renvoie un booléen pour indiquer si une valeur donnée est
présente ou non dans un set que vous passerez en paramètre avec la valeur à rechercher.
3. Modifiez cette fonction en lui passant maintenant en paramètres 2 littérateurs de set<int>(début et
fin) ainsi que la valeur à rechercher.
4. Passer la fonction en Template de façon à ce qu’elle marche peu importe le type d’itérateur qui
lui est fourni (itérateur de liste, de vecteur, d’ensemble, …).
Donner un exemple d’appel sur : un vecteur de string, une liste d’entiers, un tableau ‘classique’ de float.*/
#include <iostream>
#include <set>
#include <vector>
#include <list>
using namespace std;
template<typename iter , typename T>
bool findtemp(T a , iter D , iter F ){
    for(auto it = D ; it!=F;it++){
        if(*it==a){
            return true ;
        }
    }
    return false ;
    
}



bool findit(int r , set<int>::iterator D , set <int>::iterator F){
    for(set <int>::iterator i = D ; i!=F ; i++){
        if(*i == r ){
            return true ; 
        }
    }
    return false ;
}

bool find(int r , set<int> f){
    return f.find(r)!=f.end() ;
}

int main (){
    set <int> s ;
    for(int i = 1 ; i<=100 ; i++){
        s.insert(i);
    }
    cout << find(23,s) << endl ;;
    cout << findit(33 , s.begin() , s.end()) << endl ;
    cout << findtemp(5.6,s.begin(),s.end()) << endl ;
    float t[3] = {2.2 ,24.3, 34.00};
    cout << findtemp(2.2f,t,t+3) << endl;
    list<int> l ;
    l.push_back(23);
    l.push_back(24);
    l.push_back(25);
    cout << findtemp(23,l.begin(),l.end()) << endl ;
    vector<string> v ;
    v.push_back("yassine");
    v.push_back("yassin");
    v.push_back("yassi");
    v.push_back("yass");
    cout << findtemp(string("yass"),v.begin(),v.end()) << endl;
}