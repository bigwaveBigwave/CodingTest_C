#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(int a, int b) {
	if (a % 5 != b % 5) return a % 5 < b % 5;
	return a < b;
}
int main() {
	int a[5] = { 1, 4, 5, 2, 7 };
	sort(a, a + 5);//마지막 인자는 원소의 길이만큼 +하기.

	vector<int> b = { 1, 4, 5, 2, 7 };
	sort(b.begin(), b.end());


	return 0;
}