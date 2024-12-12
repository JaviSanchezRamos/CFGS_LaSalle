// GAME OF NIM


#include <iostream>
using namespace std;

int main()
{
	int NumInicial;
	string jugador1, jugador2;
	bool play = true;

	cout << "Nom del jugador 1: ";
	cin >> jugador1;

	cout << "Nom del jugador 2: ";
	cin >> jugador2;

	cout << "Numero Inicial: ";
	cin >> NumInicial;

	while (play) {

		int Resta1, Resta2;
		
		cout << jugador1 << ", quin numero (1 o 2) vols restar a " << NumInicial << ":\n";
		cin >> Resta1;

		switch (Resta1)
		{
		case 1:
			cout << "Restant numero 1 a " << NumInicial << ".\n";
			NumInicial -= 1;
			break;

		case 2:
			cout << "Restant numero 2 a " << NumInicial << ".\n";
			NumInicial -= 2;
			break;

		default:
			cout << "Numero no correcte.\n";
			continue;  
		}

		
		cout << "Total: " << NumInicial << "\n";
		if (NumInicial == 0) {
			cout << jugador1 << " ha guanyat!\n";
			break;
		}

		while (true) {

			cout << jugador2 << ", quin numero (1 o 2) vols restar a " << NumInicial << ":\n";
			cin >> Resta2;

			switch (Resta2)
			{
			case 1:
				cout << "Restant numero 1 a " << NumInicial << ".\n";
				NumInicial -= 1;
				break;

			case 2:
				cout << "Restant numero 2 a " << NumInicial << ".\n";
				NumInicial -= 2;
				break;

			default:
				cout << "Numero no correcte.\n";
				continue;  
			}
			break;  
		}

		cout << "Total: " << NumInicial << "\n";

		if (NumInicial == 0) {
			cout << jugador2 << " ha guanyat!\n";
			break;
		}
		
	}



	
}

