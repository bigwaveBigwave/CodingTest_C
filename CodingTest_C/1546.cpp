#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	double N;
	cin >> N;
	double max_value = 0;
	vector<int> v(N);
	vector<int> v2(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (v[i] > max_value) {
			max_value = v[i];
		}
	}

	double temp = 0;

	for (int i = 0; i < N; i++) {
		

		v2[i] = v[i]/max_value*100;
		temp = temp + v2[i];
	}

	cout << temp / N;








	return 0;
}