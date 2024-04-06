#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	bool isBeginning = true, isEnd = true;
	vector<bool> lessons;
	//vector<bool> lessons(n);

	for (int i = 0; i < n; i++) {
		bool temp;
		cin >> temp;
		lessons.push_back(temp);
	}

	// 'trim' beggining & end free hours
	while (isBeginning) {
		if (!lessons.empty() and lessons[0] == 0) {
			lessons.erase(lessons.begin());
		}
		else {
			isBeginning = false;
		}
	}

	while (isEnd) {
		if (!lessons.empty() and lessons[lessons.size() - 1] == 0) {
			lessons.pop_back();
		}
		else {
			isEnd = false;
		}
	}

	int size = lessons.size(); // size after trimming

	if (size == 0) {
		cout << 0;
	}
	else {
		int counter = 1; // first is always 1 (trimmed)

		for (int i = 1; i < size; i++) {
			if (lessons[i]) {
				counter++;
			}
			else if (lessons[i + 1] and lessons[i - 1]) {
				counter++;
			}
		}

		cout << counter;
	}
}

/*
14
0 0 0 1 0 1 0 0 1 0 0 0 1 1 0

--> 4
*/