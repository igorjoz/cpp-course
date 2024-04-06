#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

struct phoneBook {
    int id;
    string name;
    string surname;
    string phoneNumber;
};

// unikalny uzytkownik moze miec to samo imie i nazwisko, ale nie moze miec takiego samego numeru telefonu
phoneBook database[100] = {
        //1, "Janusz", "Nowak", "065195238",
        //2, "Karol", "Wojt", "539642896",
        //3, "Alex", "Zebra", "122322422",
        //4, "Kamil", "Kamieniecki", "123456789",
        //5, "Aleksander", "Maly", "987654321",
        //6, "Aleksander", "Maly", "000111222"
};

//int totalUsers = 6;

void showUserData(int id) {
    id -= 1;
    cout << database[id].name << " " << database[id].surname << " [" << database[id].id << "]" << endl;
    cout << database[id].phoneNumber << endl;
}

void findUserByPhoneNumber() {
    string phoneNumber;
    cout << endl << "Podaj numer telefonu uzytkownika do wyszukania: ";
    cin >> phoneNumber;

    bool isExistent = false;

    for (int i = 0; i < totalUsers; i++) {
        if (database[i].phoneNumber == phoneNumber) {
            cout << "Znaleziono takiego uzytkownika!" << endl;
            showUserData(database[i].id);
            isExistent = true;
            break;
        }
    }
    if (!isExistent) {
        cout << "Przepraszamy, ale osoba o numerze telefonu " << phoneNumber << " nie jest zarejestrowana w naszej ksiazce telefonicznej" << endl;
        cout << "Czy chcesz ja dodac? [t/n]";
    }
}

void findUserByNameAndSurname() {
    string name;
    string surname;
    cout << endl << "Podaj imie uzytkownika do wyszukania: ";
    cin >> name;
    cout << "Podaj nazwisko uzytkownika do wyszukania: ";
    cin >> surname;

    bool isExistent = false;

    for (int i = 0; i < totalUsers; i++) {
        if (database[i].name == name && database[i].surname == surname) {
            cout << "Znaleziono takiego uzytkownika!" << endl;
            showUserData(database[i].id);
            isExistent = true;
        }
    }
    if (!isExistent) {
        cout << "Przepraszamy, ale osoba \"" << name << surname << "\" nie jest zarejestrowana w naszej ksiazce telefonicznej" << endl;
        cout << "Czy chcesz ja dodac? [t/n]";
    }
}

void addUser() {
    string name, surname, phoneNumber;
    cout << "Podaj imie nowego uzytkownika: ";
    cin >> name;
    cout << "Podaj nazwisko nowego uzytkownika: ";
    cin >> surname;
    cout << "Podaj numer telefonu nowego uzytkownika: ";
    cin >> phoneNumber;

    bool validation = true;
    for (int i = 0; i < totalUsers; i++) {
        if (database[i].phoneNumber == phoneNumber) {
            validation = false;
            break;
        }
    }
    if (!validation) {
        cout << "Przepraszamy, ale numer telefonu " << phoneNumber << " juz jest zarejestrowany w naszej ksiazce telefonicznej i nie mozemy dodac uzytkownika o takim samym numerze teleofnu" << endl;
    }
    else {
        database[totalUsers].id = totalUsers + 1;
        database[totalUsers].name = name;
        database[totalUsers].surname = surname;
        database[totalUsers].phoneNumber = phoneNumber;

        totalUsers++;
    }
}

int main()
{
    //char character;
    //character = getchar();
    //cout << character;
    
    addUser();
    findUserByPhoneNumber();
    findUserByNameAndSurname();

    cout << endl;
}