#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int boughtTicketsQuantity, maxInCar, tickets;
    long long currentCar, searchedCar;

    map<long long, int> cars;
    map<long long, int>::iterator it;

    cin >> boughtTicketsQuantity >> maxInCar >> searchedCar;

    for (int i = 0; i < boughtTicketsQuantity; i++) {
        cin >> currentCar >> tickets;

        if (cars[currentCar] + tickets <= maxInCar) {
            cars[currentCar] += tickets;
        }
    }

    cout << cars.size() << endl;

    for (it = cars.begin(); it != cars.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    it = cars.lower_bound(searchedCar);

    if (it == cars.end()) {
        it--;
    }

    cout << it->first << " " << it->second;
}