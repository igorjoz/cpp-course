#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int pointsQuantity;
	int minTriangleArm;
	int maxX = 0, maxY = 0;
	bool equalMaxXAndY = false;

	cin >> pointsQuantity;

	for (int i = 0; i < pointsQuantity; i++) {
		int x, y;

		cin >> x >> y;

		if (x == y and x >= maxX and y >= maxY) {
			maxX = x;
			maxY = y;
			equalMaxXAndY = true;
		}
		else if (x > maxX) {
			maxX = x;
			equalMaxXAndY = false;
		}
		else if (y > maxY) {
			maxY = y;
			equalMaxXAndY = false;
		}
	}

	//cout << maxX << " " << maxY << " " << equalMaxXAndY << " " << endl;

	if (equalMaxXAndY) {
		cout << maxX + 2;
	}
	else {
		cout << max(maxX, maxY) + 1;
	}
}