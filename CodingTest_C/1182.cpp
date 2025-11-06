#include<iostream>
using namespace std;

//n개의 수가 들어있는 집합의 공집합을 제외한 
//부분집합의 경우의 수 중 합이 S가 되는 경우의 개수를 구하기

int arr[30];
int cnt = 0;
int N, S;
bool isused[502];

void func(int cur, int tot) {
	if (cur == N) {
		if (tot == S) cnt++;
		return;
	}
	func(cur + 1, tot);
	func(cur + 1, tot + arr[cur]);

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	func(0, 0);
	if (S == 0) cnt--;
	cout << cnt;

	return 0;
}
