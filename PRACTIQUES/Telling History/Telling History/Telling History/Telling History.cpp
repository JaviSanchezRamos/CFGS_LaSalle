#include <iostream>
#include <stdlib.h> // Amb aquesta llibreria podem netejar la consola
#include <string>
#include <Windows.h> // per a la funcio sleep
using namespace std;

int main() {
    // Variables
  string hero_name, weapon_color;
  int age, morale_level;
  double num_ammo;
  float accuracy;
  bool has_grenade;
  char name_army[5];
  bool play = true;
    while (play){
    // Entrada de dades
    cout << "What's the name of the protagonist? ";
    getline(cin, hero_name);  // String

    cout << "What's the protagonist's age? ";
    cin >> age;  // Int

    cout << "What color is the protagonist's weapon? ";
    cin >> weapon_color;  // String

    cout << "How many shots are left in the protagonist's weapon? ";
    cin >> num_ammo;  // double (tot i que ha de ser un int)

    cout << "Enter your shooting accuracy (0.0 to 1.0): ";
    cin >> accuracy;  // Float

    cout << "Do you have a grenade? (yes=1 / no=0): ";
    cin >> has_grenade;  // Bool

    cout << "Enter your morale level (1-10): ";
    cin >> morale_level;  // Int

    cout << "Enter 5 character to make a army name: ";
    cin >> name_army; //char

    // Operació matemàtica: calcular la potència de foc total
    float firepower = num_ammo * accuracy;  // Operació entre float i int
    // Inici de la història
    
        cout << "\n--- Alien Invasion: The Final Stand ---" << endl;
        Sleep(500);
        cout << "The year is 2045. Earth is under attack by alien forces." << endl;
        Sleep(500);
        cout << "You, Commander " << hero_name << ", at " << age << " years old, must eliminate the alien leader." << endl;
        Sleep(500);
        cout << "Armed with your " << weapon_color << " laser rifle, you only have " << num_ammo << " shots left." << endl;
        Sleep(500);
        cout << "Your firepower is calculated to be " << firepower << " based on your ammo and accuracy." << endl;
        Sleep(500);
        cout << "Your morale level is " << morale_level << " out of 10." << endl;
        Sleep(500);

        cout << "\n #You entered the alien's ship and saw four guardians at the door of the main chamber, where the leader was managing his '" << name_army << "' army." << endl;
        Sleep(500);
        // Si la moral que ha introduït l'usuari és més gran que 7
        if (morale_level > 7) {
            cout << " Your high morale gives you confidence, and you take out the guards without using any ammunition.  " << endl;
            Sleep(500);
        }
        else { // sinó
            if (has_grenade == true) { // si l'usuari ha entrat que té granada
                cout << "You remember that you have one grenade, so you take it and throw it at the guards. Then, you run to the main door" << endl;
                Sleep(500);
            }
            else { // si no té granada
                cout << "You hesitate and alert the guards. You manage to escape, but waste four shots." << endl;
                Sleep(500);
                num_ammo -= 4;
            }

        }
        cout << "#You cross the door to the main chamber and see the leader sitting on his throne" << endl;
        Sleep(500);
         
        if (firepower >= 5) { // si la dada calculada es major de 5
            cout << "You shoot twice, once in the head and once in the chest, and the alien leader falls over, dying instantly. " << endl;
            Sleep(500);
        }
        else { // sinó
            cout << "You still have your weapon and shoot twice, once at the head and once at the chest, but you miss both shots. The alien leader sees you, stands up, and goes for his blaster. " << endl;
            Sleep(500);
            cout << " He shoots you, and you die instantly." << endl;
            Sleep(500);
        }
        // preguntem si vol tornar a jugar
        cout << " Do you want to play again? (yes=1/no=0): " << endl; 
        cin >> play;
        cin.ignore(); // borra el get line entrat

        if (play){ // si vol jugar
            system("cls"); // borra la terminal
        }
        else {
            cout << "Closing...";
            play = false;
        }
    }
return 0;
}



    




