#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long number) {
    if (number == 0 or number == 1) {
        return false;
    }
    else if (number == 2) {
        return true;
    }

    if (number % 2 == 0) {
        return false;
    }

    for (int i = 3; i <= (int)(sqrt(number)); i++) {
        cout << (int)(sqrt(number)) << "  ";
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    /*for (long long i = 0; i < 200; i++) {
        cout << i << ": " << isPrime(i) << "\n";
    }*/



    int k = 1;
    int primeNumbersToGenerate;
    int counter = 0;
    int testedNumber = 2;
    int d = 1;
    bool t;

    cin >> primeNumbersToGenerate;
    int* primeNumbers = new int[primeNumbersToGenerate];

    while (counter < primeNumbersToGenerate) {
        t = true;
        if (counter < 3) testedNumber += counter;
        else {
            testedNumber = 6 * k + d;

            if (d == 1) {
                d = -1;
                k++;
            }
            else {
                d = 1;
            }

            for (int i = 2; primeNumbers[i] <= (unsigned int)sqrt(testedNumber); i++) {
                if (!(testedNumber % primeNumbers[i])) {
                    t = false;
                    break;
                }
            } 
        }

        if (t) {
            primeNumbers[counter++] = testedNumber;
            cout << testedNumber << " ";
        }
    }

    delete[] primeNumbers;
}