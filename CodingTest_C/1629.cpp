#include<iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b, c;
	long long val = 1;
	cin >> a >> b >> c;

	while (b--) {
		val = val * a % c;
	}

	cout << val;


	

	return 0;
}
