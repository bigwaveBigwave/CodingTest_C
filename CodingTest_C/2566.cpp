#include<iostream>
#include<stack>
#include<vector>
#include<iomanip>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int max = -1;
	int a, b = 1;

	vector<vector<int>> v1(9, vector<int>(9));

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> v1[i][j];
			if (v1[i][j] > max) {
				max = v1[i][j];
				a = i + 1;
				b = j + 1;

			}
		}
	}





	cout << max << endl;
	cout << a << " " << b;



	return 0;
}