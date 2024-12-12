// Introdueix un valor en ftemp (Fahrenheit) i convertir en ctemp (Celsius). A continuació, imprimiu el  Resultats. (Consell: la fórmula de conversió inversa és ctemp = (ftemp − 32) / 1.8.)


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float ftemp, ctemp;
    cout << "Indica la temperatura en Fahrenheit: ";
    cin >> ftemp;
    ctemp = (ftemp - 32) / 1.8;
    cout << fixed << setprecision(2);
    cout << "La temperatura en Celsius es: " << ctemp << " graus celsius.";
    return 0;
    
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
