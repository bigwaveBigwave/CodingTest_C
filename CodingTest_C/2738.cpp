#include<iostream>
#include<stack>
#include<vector>
#include<iomanip>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;

	cin >> N >> M;

	vector<vector<int>> v1(N, vector<int>(M));
	vector<vector<int>> v2(N, vector<int>(M));
	vector<vector<int>> v3(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v1[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v2[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			v3[i][j] = v1[i][j] + v2[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << v3[i][j] << " ";
		}
		cout << endl;
	}



	return 0;
}