#include <iostream>
#include <string>
using namespace std;

struct Jugador {
    string Name;
    int Score;
};

int main() {
    // Definir los nombres y puntuaciones de los jugadores
    string nombres[] = { "Anna", "Marc", "Joan" };
    int puntuaciones[] = { 58, 74, 80 };

    // Definir la cantidad de jugadores
    int numJugadores = 3;

    // Crear una estructura para almacenar el jugador con la puntuación máxima
    Jugador ganador;
    ganador.Score = 0; // Iniciar con un valor bajo para garantizar que se actualice

    // Comparar las puntuaciones y encontrar el jugador con la puntuación más alta
    for (int i = 0; i < numJugadores; i++) {
        if (puntuaciones[i] > ganador.Score) {
            ganador.Score = puntuaciones[i];
            ganador.Name = nombres[i];
        }
    }

    // Imprimir el nombre del ganador y su puntuación
    cout << "Guanyador: " << ganador.Name << " amb " << ganador.Score << " punts." << endl;

    return 0;
}
