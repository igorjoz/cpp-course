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
phoneBook database[100] = {};

fstream databaseFile;
int totalUsers = 0;

void showUserData(int id) {
    id -= 1;
    cout << database[id].name << " " << database[id].surname << " [" << database[id].id << "]" << endl;
    cout << database[id].phoneNumber << endl << endl;
}

void showAllUsersData() {
    for (int i = 1; i <= totalUsers; i++) {
        showUserData(i);
    }
}

void findUserByPhoneNumber() {
    string phoneNumber;
    cout << "Podaj numer telefonu uzytkownika do wyszukania: ";
    cin >> phoneNumber;

    bool isExistent = false;

    for (int i = 0; i < totalUsers; i++) {
        if (database[i].phoneNumber == phoneNumber) {
            cout << "Znaleziono uzytkownika:" << endl;
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
    cout << "Podaj imie uzytkownika do wyszukania: ";
    cin >> name;
    cout << "Podaj nazwisko uzytkownika do wyszukania: ";
    cin >> surname;

    bool isExistent = false;

    for (int i = 0; i < totalUsers; i++) {
        if (database[i].name == name && database[i].surname == surname) {
            cout << "Znaleziono uzytkownika:" << endl;
            showUserData(database[i].id);
            isExistent = true;
        }
    }
    if (!isExistent) {
        cout << "Przepraszamy, ale osoba \"" << name << " " << surname << "\" nie jest zarejestrowana w naszej ksiazce telefonicznej" << endl;
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
        cout << "Przepraszamy, ale numer telefonu " << phoneNumber << " juz jest zarejestrowany w naszej ksiazce telefonicznej i nie mozna dodac uzytkownika o tym samym numerze telefonu" << endl;
    }
    else {
        database[totalUsers].id = totalUsers + 1;
        database[totalUsers].name = name;
        database[totalUsers].surname = surname;
        database[totalUsers].phoneNumber = phoneNumber;

        databaseFile.open("database.txt", ios::app);
        if (databaseFile.good()) {
            databaseFile << endl;
            databaseFile << database[totalUsers].id << " ";
            databaseFile << database[totalUsers].name << " ";
            databaseFile << database[totalUsers].surname << " ";
            databaseFile << database[totalUsers].phoneNumber;
        }
        else {
            cout << endl << "Problem z plikiem bazy danych przy dodawaniu danych" << endl;
        }

        totalUsers++;
    }
}

int main()
{
    databaseFile.open("database.txt", ios::in);
    if (databaseFile.good()) {
        string temp;
        while (!databaseFile.eof()) {
            totalUsers++;
            database[totalUsers - 1].id = totalUsers;
            databaseFile >> temp;
            databaseFile >> temp;
            database[totalUsers - 1].name = temp;
            databaseFile >> temp;
            database[totalUsers - 1].surname = temp;
            databaseFile >> temp;
            database[totalUsers - 1].phoneNumber = temp;
        }

        databaseFile.close();

        showUserData(1);
        showUserData(2);
        showAllUsersData();

        //addUser();
        findUserByPhoneNumber();
        findUserByNameAndSurname();
    }
    else {
        cout << endl << "Problem z plikiem bazy danych przy odczycie danych";
    }

    databaseFile.close();

    cout << endl;
}