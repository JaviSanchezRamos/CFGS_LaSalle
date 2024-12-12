
#include <iostream>
#include "funciones.h"

using namespace std;


int main()
{

    int opcion;

    cout << "Selecciona l'exercici:" << endl;
    cout << "1. Numero factorial" << endl;
    cout << "2. Numero primer" << endl;

    cin >> opcion;

    switch (opcion) {

    case 1: {

        int num;
        bool play = true;

        while (play) {

            cout << "Dona'm un numero: ";
            cin >> num;

            if (num <= 0) {
                cout << "El numero ha de ser mes gran que 0." << endl;

            }
            else {

                factorial(num);
                play = false;

            }

        }
        break;
    }

    case 2: {

        int num2;
        bool play2 = true;

        while (play2) {
            cout << "Dona'm un numero: ";
            cin >> num2;

            if (num2 <= 2) {

                cout << "El numero ha de ser mes gran que 2." << endl;
            }
            else {
                EsPrimer(num2);
                play2 = false;
            }
        }
        break;
    }
    }
    return 0;
}
