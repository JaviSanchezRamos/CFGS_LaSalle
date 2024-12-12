//Algoritme de vida del jugador : Crea un algoritme que permeti introduir la vida actual del jugador i restar - hi el dany rebut.
//Si la vida del jugador és 0 o inferior, mostra un missatge que digui "Game Over", i si la vida és positiva, mostra "Encara tens X punts de vida".

#include <iostream> 
using namespace std;

int main()
{
	int listSize = 4;
	int numberProcessed = 0;
	double sum = 0;
	while (numberProcessed < listSize) {
		double value;
		cout << "Number: ";
		cin >> value;
		sum += value;
		++numberProcessed;
	}
	double average = sum / numberProcessed;
	cout << "Average: " << average << endl;

return 0;
}


