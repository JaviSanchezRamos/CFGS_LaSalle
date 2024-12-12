// Soc en Javier Sánchez Ramos.

// 1 Demanar a l'usuari l'edat i indicar a quin any pots entrar a instagram
#include <iostream>
using namespace std;

int main()
{
    int edat, minim_edat;
    cout << "Diga'm la teva edat: ";
    cin >> edat;

    minim_edat = 16 - edat;
    if (edat < 16) {
        cout << "Per entrar a instagram necessites 16 anys. Voste podra entrar d'aqui  " << minim_edat << " edat." << endl;
    }
    else {
        cout << "Voste ja te la minima edat per entrar a instagram." << endl;

    }



// 2 Demani l'any actual i l'any de naixement per tal de calcular l'edat.

    int any, any_actual;
    

    cout << "Quin es l'any actual? ";
    cin >> any_actual;
    cout << "Quin any vas neixer? ";
    cin >> any;

    int edat2;
    edat2 = any_actual - any;

    cout << "La teva edat es " << edat2 << " anys.";

    return 0;
}