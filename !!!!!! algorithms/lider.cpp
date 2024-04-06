#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int QUANTITY = 80;

int main()
{
    int nums[QUANTITY];
    int counter = 0;
    int leaderValue;
    bool doesLeaderExist;

    srand((unsigned)time(NULL));

    // generacja
    leaderValue = rand() % 100;
    for (int i = 0; i < QUANTITY; i++) {
        if (rand() % 2) {
            nums[i] = rand() % 100;
        }
        else {
            nums[i] = leaderValue;
        }
    }    


    // g³ówny program
    for (int i = 0; i < QUANTITY; i++) {
        if (!counter) {
            leaderValue = nums[i];
            counter = 1;
        }
        else if (leaderValue == nums[i]) {
            counter++;
        }
        else {
            counter--;
        }
    }


    if (!counter) {
        doesLeaderExist = false;
    }
    else {
        counter = 0;
        for (int i = 0; i < QUANTITY; i++) {
            if (leaderValue == nums[i]) {
                counter++;
            }
        }
        doesLeaderExist = counter > QUANTITY / 2;
    }


    // wypisanie
    for (int i = 0; i < QUANTITY; i++) {
        if (doesLeaderExist && (nums[i] == leaderValue)) {
            cout << " >" << setw(2) << nums[i];
        }
        else {
            cout << setw(4) << nums[i];
        }
    }
    cout << endl;

    if (doesLeaderExist) {
        cout << leaderValue << ": " << counter;
    }
    else {
        cout << "BRAK LIDERA";
    }
}