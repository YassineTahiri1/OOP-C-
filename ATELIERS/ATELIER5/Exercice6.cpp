#include <iostream>
using namespace std;
template <class T> class point
{ T x, y ; // coordonnees
public :
point (T abs, T ord) { x = abs ; y = ord ; }
void affiche () ;
} ;
template <class T> void point<T>::affiche ()
{ cout << "Coordonnees : " << x << " " << y << "\n" ;
}
// Question a :
// le programme ne va pas afficher les nombre car il est les considerent comme characteres

// Question b : (on lui indique le type)

template <class T>
void point<T>::affiche() {
    cout << "Coordonnees : " << int(x) << " " << int(y) << "\n";
}