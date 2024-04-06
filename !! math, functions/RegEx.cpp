#include <iostream>
#include <regex>
#include <ctime>

using namespace std;

void search(string address, smatch matches, regex pattern, float number) {
	cout << "Przeszukiwanie " << number << endl;

	while (regex_search(address, matches, pattern)) {
		for (auto x : matches) {
			cout << "[" << x << "]";
		}

		address = matches.suffix().str();
		cout << " -> " << address << endl;
	}
	cout << endl;
}

void replace(string address, regex pattern, string replaceStr, float number) {
	cout << "Podmiana " << number << endl;
	string newAddress = regex_replace(address, pattern, replaceStr);
	cout << newAddress << endl << endl;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");

	string address = "ul. W¹brzeska 37, 82-500 Kwidzyn, Polska";

	smatch matches;
	regex pattern("(.*?)([0-9]+)(.*)");
	//regex pattern(".*?[0-9]+.*");
	if (regex_match(address, matches, pattern)) {
		cout << "Found " << matches.size() << " matches" << endl;

		for (int i = 0; i < matches.size(); i++) {
			cout << matches[i] << endl;
		}
		cout << endl;
	}

	// przeszukiwanie

	pattern = "[0-9]+([, -//]+)";
	search(address, matches, pattern, 1);

	pattern = "[0-9]{2}";
	search(address, matches, pattern, 2);

	pattern = "[a-zA-Z¹]+";
	search(address, matches, pattern, 3.1);

	pattern = "[a-zA-Z¹]";
	search(address, matches, pattern, 3.2);

	pattern = ".*?,";
	search(address, matches, pattern, 4);

	pattern = "^.{10}";
	search(address, matches, pattern, 5);

	pattern = "^.{1,5}";
	search(address, matches, pattern, 6);

	// podmiana
	string replaceStr = "";

	pattern = "[a-zA-Z]{2}";
	replaceStr = ":)";
	replace(address, pattern, replaceStr, 1);

	pattern = "[a-zA-Z]{2}(...)";
	replaceStr = "$1";
	replace(address, pattern, replaceStr, 2);

	pattern = "([0-9]{2})-([0-9]{3})";
	replaceStr = "$2-$1";
	replace(address, pattern, replaceStr, 3);
}