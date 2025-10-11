#include <iostream>
using namespace std;

void remplir(int* arr, int n) {
    cout << "Remplissez le tableau :\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << " : ";
        cin >> *(arr + i);
    }
}

void afficher(const int* arr, int n) {
    cout << "Les éléments du tableau sont : ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int& trouverMax(int* arr, int n) {
    int* maxPtr = arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > *maxPtr) {
            maxPtr = arr + i;
        }
    }
    return *maxPtr;
}

void inverser(int* arr, int n) {
    int* D = arr;
    int* F = arr + n - 1;
    int tmp;
    while (D < F) {
        tmp = *D;
        *D = *F;
        *F = tmp;
        D++;
        F--;
    }
}

void inverserAvecTableau(int* arr, int n) {
    int* temp = new int[n];
    for (int i = 0; i < n; i++) {
        *(temp + i) = *(arr + n - 1 - i);
    }
    for (int i = 0; i < n; i++) {
        *(arr + i) = *(temp + i);
    }
    delete[] temp;
}

int main() {
    int n;
    cout << "Entrez la taille du tableau : ";
    cin >> n;

    int* arr = new int[n];

    remplir(arr, n);
    cout << "Tableau original : ";
    afficher(arr, n);

    int& M = trouverMax(arr, n);
    cout << "Le maximum du tableau est : " << M << endl;

    cout << "Tableau inversé (en place) : ";
    inverser(arr, n);
    afficher(arr, n);

    cout << "Tableau inversé (avec tableau intermédiaire) : ";
    inverserAvecTableau(arr, n);
    afficher(arr, n);

    delete[] arr;
    return 0;
}
