#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const int QUANTITY = 100;
    int nums[QUANTITY];
    int counter, maxCounter = 0;
    int maxValue;

    srand((unsigned)time(NULL));
    for (int i = 0; i < QUANTITY; i++) {
        nums[i] = rand() % 100;
    } 



    maxValue = nums[0] - 1;
    for (int i = 0; i < QUANTITY - maxCounter; i++)  {
        if (nums[i] != maxValue) {
            counter = 1;
            for (int j = i + 1; j < QUANTITY; j++) {
                if (nums[j] == nums[i]) {
                    counter++;
                }
            }

            if (counter > maxCounter) {
                maxCounter = counter;
                maxValue = nums[i];
            }
        }
    }



    for (int i = 0; i < QUANTITY; i++) {
        if (nums[i] == maxValue) {
            cout << " >" << setw(2) << nums[i];
        }
            
        else {
            cout << setw(4) << nums[i];
        }     
    }

    cout << endl << maxValue << ": " << maxCounter;
}