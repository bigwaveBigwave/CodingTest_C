#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	int u, k;
	int temp = 0;

	cin >> N;
	cin >> M;

	vector<int> v1(N);
	for (int i = 0; i < N; i++) {
		v1[i] = i + 1;
	}

	for (int i = 0; i < M; i++) {
		cin >> u;
		cin >> k;

		temp = v1[u - 1];
		v1[u - 1] = v1[k - 1];
		v1[k - 1] = temp;

	}

	for (int i = 0; i < N; i++) {
		cout << v1[i] << " ";
	}





	return 0;
}