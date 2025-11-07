#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


long long N;

int main() {
	cin >> N;
	vector<long long> v(N);

	for (int i = 0; i < N; i++) {
		long long a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	long long mxval = -2 ^ 62 - 1;
	int mxcnt = 0;

	for (int i = 0; i < N; i++) {
		if (i == 0 || v[i - 1] == v[i]) {
			cnt++;
		}
		else {
			if (cnt > mxcnt) {
				mxcnt = cnt;
				mxval = v[i - 1];
			}
			cnt = 1;
		}
	}
	if (cnt > mxcnt) mxval = v[N - 1];
	cout << mxval;
	return 0;
}