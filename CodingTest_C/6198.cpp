#include<iostream>
#include<vector>
using namespace std;


int main() {
	int N;
	int total = 0;
	cin >> N;
	vector<int> v1;
	for (int i = 0; i < N; i++) {
		cin >> v1[i];
	}

	for (int j = 0; j < N-1; j++) {
	
		for (int t = 1; t < N; t++ ) {

			if (v1[j] >= v1[j + t]) {
				total++;
			}
			
		}
	}

	cout << total;

	return 0;
}