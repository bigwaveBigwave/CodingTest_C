#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	

	cin >> N;
	vector<int> numbers(N);
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
		
	}

	int maxVal = numbers[0];
	int minVal = numbers[0];

	for (int i = 0; i < N; i++) {
		if (numbers[i] > maxVal) {
			maxVal = numbers[i];
		}
		else if (numbers[i] < minVal) {
			minVal = numbers[i];
		}
	}

	cout << minVal << " " << maxVal;







	return 0;
}