#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int digit_sum(const string& s) {
	int sum = 0;
	for (char c : s) {
		if (c >= '0' && c <= '9') sum += c - '0';
	}
	return sum;
}

bool cmp(const string &a, const string &b) {
	if (a.length() != b.length()) return a.length() < b.length();
	int sa = digit_sum(a);
	int sb = digit_sum(b);
	if (sa != sb) return sa < sb;
	return a < b; //기본 사전순 비교
}
int N;
int main() {
	cin >> N;
	vector<string> v;
	for (int i = 0; i < N; i++) {
		//cin >> v[i]; -> v가 비어있는 상태면 이렇게할 때 잘못된 메모리에 접근해서 프로그램이 터짐
		//v.resize(N)하거나 push_back사용하기
		string s;
		cin >> s;
		v.push_back(s);
	}



	sort(v.begin(), v.end(), cmp);

	for (const auto& s : v) cout << s << '\n';
	return 0;
}