#include<iostream>
#include<stack>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int N;
	cin >> N;

	long long ans = 0;
	stack<long long> st;
	for (int i = 0; i < N; i++) {
		long long h;
		cin >> h;

		while (!st.empty() && st.top() <= h) {
			st.pop();
		}

		ans += st.size();

		st.push(h);
	}

	cout << ans << '\n';




	return 0;
}