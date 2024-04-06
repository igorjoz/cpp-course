#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

static bool comp2DVectorSecondElement(vector<int>& a, vector<int>& b) {
	return a[1] > b[1];
}

static bool compVectorOfSetsFirstElement(set<string>& a, set<string>& b) {
	return *a.begin() < *b.begin();
}

void display2DVector(vector<vector<int>> nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums[i].size(); j++) {
			cout << nums[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

void displayVectorOfSets(vector<set<string>> words) {
	for (int i = 0; i < words.size(); i++) {
		for (auto j = words[i].begin(); j != words[i].end(); j++) {
			cout << *j << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	// 2d vector
	vector<vector<int>> nums;

	for (int i = 0; i < 10; i++) {
		vector<int> num;
		num.push_back(i);
		num.push_back(i * 2 + 1);
		nums.push_back(num);
	}
	display2DVector(nums);

	sort(nums.begin(), nums.end());
	display2DVector(nums);

	sort(nums.begin(), nums.end(), comp2DVectorSecondElement);
	display2DVector(nums);


	// vector of sets
	vector<set<string>> words = {
		{ "karol", "jan", "adam", "marek", "stasiu", "igor", "wiktor" },
		{ "dzik", "baran", "ptak", "czlek", "dzdzownica" },
		{ "terran", "kerigan", "protos", "zerg" },
		{ "arek", "zotin", "warchol", "kamilek" },
		{ "aaa", "aks", "tos", "mark" },
		{ "adama", "fuks", "tik", "tak" },
	};
	displayVectorOfSets(words);

	sort(words.begin(), words.end(), compVectorOfSetsFirstElement);
	displayVectorOfSets(words);
}