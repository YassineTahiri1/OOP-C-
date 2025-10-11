#include<iostream>
using namespace std ;

int main (){

/*
    Exercice 3 
Soient les déclarations suivantes :  
int n = 5, p = 9 ;  
int q ;  
float x ;  
Quelle est la valeur affectée aux différentes variables concernées par chacune des instructions 
suivantes ?  
q = n < p ;                         
q = n == p ;                        
q = p % n + p > n ;               
x = p / n ;                       
x = (float) p / n ;        
x = (p + 0.5) / n ;               
x = (int) (p + 0.5) / n ;         
q = n * (p > n ? n : p) ;          
q = n * (p < n ? n : p) ;         
}

*/

    cout << "1) q = n < p = 1   Type:int\n";
    cout << "2) q = n == p = 0   Type:int\n";
    cout << "3) q = p % n + p > n = 1   Type:int\n";
    cout << "4) x = p / n = 1   Type:float\n";
    cout << "5) x = (float)p / n = 1.8   Type:float\n";
    cout << "6) x = (p + 0.5) / n = 1.9   Type:float\n";
    cout << "7) x = (int)(p + 0.5) / n = 1   Type:float\n";
    cout << "8) q = n * (p > n ? n : p) = 25   Type:int\n";
    cout << "9) q = n * (p < n ? n : p) = 45   Type:int\n";

    return 0;
}

