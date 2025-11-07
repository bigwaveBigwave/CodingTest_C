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
	
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	long long mxval = v[0];
	int mxcnt = 0;

	for (int i = 0; i < N; i++) {
		if (i == 0 || v[i - 1] == v[i]) {//||연산자는 왼쪽이 true면 오른쪽은 평가하지 않음. v[-1]이될 경우X
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
	if (cnt > mxcnt) mxval = v[N - 1];//마지막 원소 루프 확인
	cout << mxval;
	return 0;
}