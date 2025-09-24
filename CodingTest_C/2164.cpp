#include<iostream>
#include<vector>
#include<queue>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	if (!(cin >> N))
		return 0;

	queue<int> q1;


	for (int i = 1; i <= N; ++i) {
		q1.push(i);
	}

	while (q1.size() > 1) {
		q1.pop();
		q1.push(q1.front());
		q1.pop();
		
	}

	cout << q1.front();


	return 0;
}