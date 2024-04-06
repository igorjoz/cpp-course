#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int aCompQuantity, bCompQuantity, productDegree;

    cin >> aCompQuantity;
    aCompQuantity++;

    vector<int> polynominalA(aCompQuantity);

    for (int i = 0; i < aCompQuantity; i++) {
        cin >> polynominalA[i];
    }

    cin >> bCompQuantity;
    bCompQuantity++;

    vector<int> polynominalB(bCompQuantity);

    for (int i = 0; i < bCompQuantity; i++) {
        cin >> polynominalB[i];
    }

    productDegree = aCompQuantity + bCompQuantity - 1;
    vector<int> productPolynominal(productDegree, 0);

    for (int i = 0; i < aCompQuantity; i++) {
        for (int j = 0; j < bCompQuantity; j++) {
            productPolynominal[i + j] += polynominalA[i] * polynominalB[j];
        }
    }

    cout << productDegree - 1 << " ";
    for (auto num : productPolynominal) {
        cout << num << " ";
    }
    cout << endl;
}