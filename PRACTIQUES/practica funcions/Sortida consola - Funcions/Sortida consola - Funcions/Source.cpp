#include <iostream>
#include <math.h>
#include "funciones.h"

using namespace std;

int factorial(int n) {
    int resultat = 1;

    cout << "El factorial de " << n << " es ";

    for (int i = 1; i <= n; i++) {
        resultat *= i;

        if (i < n) {
            cout << i << " * ";
        }
        else {
            cout << i << " = " << resultat << endl;
        }
    }
    return resultat;
}

bool EsPrimer(int n2) {

    double sqrt_of_n = sqrt(n2);

    for (int i = 2; i <= sqrt_of_n + 1; i++) {

        if (n2 % i == 0) {

            cout << "No es primer";
            return false;
        }

        else {
            cout << "Es primer";
            return true;
        }

    }
    return true;

}