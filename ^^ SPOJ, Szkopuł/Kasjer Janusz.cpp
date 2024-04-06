#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int customersQuantity;
	int workTime;
	int smokingTime;

	int counter = 0;
	int lastCustomerFinishTime;
	int leftTimeForSmoking;

	cin >> customersQuantity >> workTime >> smokingTime;

	vector<int> arrivalTime(customersQuantity);
	vector<int> serviceTime(customersQuantity);

	if (customersQuantity > 0) {
		cin >> arrivalTime[0] >> serviceTime[0];
	}
	
	for (int i = 1; i < customersQuantity; i++) {
		cin >> arrivalTime[i] >> serviceTime[i];

		int timeAfterLastCustomer = arrivalTime[i - 1] + serviceTime[i - 1];
		int leftTimeToNextCustomer = arrivalTime[i] - timeAfterLastCustomer;
		while (leftTimeToNextCustomer >= smokingTime) {
			leftTimeToNextCustomer -= smokingTime;
			counter++;
		}
	}

	if (customersQuantity > 0) {
		lastCustomerFinishTime = arrivalTime[customersQuantity - 1] + serviceTime[customersQuantity - 1];
		leftTimeForSmoking = workTime - lastCustomerFinishTime;
	}
	else {
		leftTimeForSmoking = workTime;
	}

	while (leftTimeForSmoking >= smokingTime) {
		leftTimeForSmoking -= smokingTime;
		counter++;
	}

	cout << counter << endl;
}