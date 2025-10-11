#include<iostream>
#include<stack>
#include<vector>
#include<iomanip>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int max = 0;
	int a, b = 0;

	vector<vector<int>> v1(81);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> v1[i][j];
		}
	}


	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (v1[i][j] > max) {
				max = v1[i][j];
				a = i;
				b =j;

			}
		}
	}


	cout << max;



	return 0;
}