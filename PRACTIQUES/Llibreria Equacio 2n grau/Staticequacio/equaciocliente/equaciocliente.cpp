// main.cpp
#include <iostream>
#include "equaciosegongrau.h"

using namespace std;

int main() {
    double a = 0, b = 0, c = 0;  

    cout << "Valor lletra a: ";
    cin >> a;

    cout << "Valor lletra b: ";
    cin >> b;

    cout << "Valor lletra c: ";
    cin >> c;

    string result = QuadraticEquation::solve(a, b, c);

    
    cout << result << std::endl;

    return 0;
}
