#include<iostream>
using namespace std ;

int main (){

/*
Exercice 2 
Soient les déclarations :  
char c = '\x05' ;  
int n = 5 ;  
long p = 1000 ;  
float x = 1.25 ;  
double z = 5.5 ;  
Quels sont le type et la valeur de chacune des expressions suivantes :  
1)   n + c + p                    
2)   * x + c                  
3)   (char) n + c              
4)   (float) z + n / 2 
*/

cout << "1)   n + c + p = 1010 Type:long   " << endl ;
cout << "2)   * x + c  = 7.5   Type:float    " << endl ;
cout << "3)   (char) n + c = 10  Type:int" << endl ;
cout << "4)   (float) z + n / 2 =7.5  Type:float " << endl ;


return 0 ;

}