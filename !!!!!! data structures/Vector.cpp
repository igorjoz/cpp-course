#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> liczby = {1,2,3,4,5};

	int suma = 0;

	for (int temp : liczby)
	{
		cout << temp << " ";
		suma += temp;
	}
	cout << endl << "Suma: " << suma << endl << endl;

	vector <int> l_srednia;
	int ile = 0;
	cout << "Ile liczb chcesz dodac: ";
	cin >> ile;

	for (int i = 0; i < ile; i++)
	{
		int temp;

		cout << i + 1 << ".: ";
		cin >> temp;
		l_srednia.push_back(temp);
	}

	float srednia = 0;

	for (int temp : l_srednia)
	{
		cout << temp << " ";
		srednia += temp;
	}

	srednia /= ile;
	cout << endl << "Srednia: " << srednia;

	cout << endl << endl << "Czy wektor jest pusty: " << l_srednia.empty() << endl;
	cout << "Wielkosc wektora: " << l_srednia.size() << endl;
	cout << "Pojemnosc wektora: " << l_srednia.capacity() << endl;

	cout << endl << "Maksymalna wielkosc wektora: " << l_srednia.max_size() << endl;

	cout << endl << "*Zmniejszenie wektora do minimalnej pojemnosci*" << endl;
	l_srednia.shrink_to_fit();
	cout << "Pojemnosc wektora po zmianach: " << l_srednia.capacity() << endl;

	cout << endl << "*Rezerwacja 100 miejsc dla wektora*" << endl;
	l_srednia.reserve(100);
	cout << "Wielkosc wektora po zmianach: " << l_srednia.size() << endl;
	cout << "Pojemnosc wektora po zmianach: " << l_srednia.capacity() << endl;
}