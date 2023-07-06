#include <iostream>
#include <random>
#include <string>
using namespace std;

int length;
char hasUpperCase;
char hasNumber;
char hasSpecialCar;

const string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string lowerCase = "abcdefghijklmnopqrstuvwxyz";
const string number = "0123456789";
const string specialCar = "!@#$%^&*";

void askLength() {
    cout << "Combien de caractere voulez-vous? ";

    while (!(cin >> length)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Veuillez entrer un entier valide: ";
    }
}

void askUpperCase() {
    cout << "Voulez-vous des caractères en majuscule? [y/n] ";
    while (!(cin >> hasUpperCase) || (hasUpperCase != 'y' && hasUpperCase != 'n')) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Veuillez entrer 'y' pour Oui ou 'n' pour Non: ";
    }
}

void askNumber() {
    cout << "Voulez-vous des chiffres? [y/n] ";
    while (!(cin >> hasNumber) || (hasNumber != 'y' && hasNumber != 'n')) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Veuillez entrer 'y' pour Oui ou 'n' pour Non: ";
    }
}

void askSpecialCar() {
    cout << "Voulez-vous des caracteres speciaux? [y/n] ";
    while (!(cin >> hasSpecialCar) || (hasSpecialCar != 'y' && hasSpecialCar != 'n')) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Veuillez entrer 'y' pour Oui ou 'n' pour Non: ";
    }
}


void pwParam() {
    askLength();
    askUpperCase();
    askNumber();
    askSpecialCar();
}

string pwGen() {
    string password;
    string validChars = lowerCase;

    if (hasUpperCase == 'y')
        validChars += upperCase;
    if (hasNumber == 'y')
        validChars += number;
    if (hasSpecialCar == 'y')
        validChars += specialCar;


    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % validChars.length();
        password += validChars[randomIndex];
    }

    return password;
}



int main()
{
    pwParam();
    cout << endl  << "Votre mot de passe est: " << pwGen() << endl;
    cout << endl << "Appuyez sur une touche pour quitter...";
    cin.ignore(); 
    cin.get();   
}
