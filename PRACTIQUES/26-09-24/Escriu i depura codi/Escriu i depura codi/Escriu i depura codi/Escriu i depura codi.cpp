//Escriu i depura el codi  
//Javier Sánchez Ramos   26/09/2024  
//Realitza un programa que indica quan ha durant una partida (en hores, minuts i segons) 
//com a dada origen indicara el numero total de segons jugats

#include <iostream>
using namespace std; // Activem l'espai de noms std

int main()
{
    // creem la variable que ens donarà l'usuari i la preguntem. 
    int numero;
    cout << "Diga'm un numero: ";
    cin >> numero;

    if (numero % 7 == 0) {
        cout << "Es multiple de 7.";
    }
    else {
        float residu;
        residu = numero % 7;
        cout << "Et falta " << 7 - residu << " per ser residu de 7";
        
    }

   return 0;
}

