#include<iostream>
#include<stack>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
	1. 문제 해석
	세자리 수가 두개 주어지면(0이 포함안된) 각 수를 뒤에서부터 읽어서 그 중 큰 수를구하기

	2. 손으로 풀기
	두 수를 문자열로 변수 두개로 입력 받기

	각 수의 순서 거꾸로 하기


	최댓값 구하기


	3. psuedo coding
	최댓값, 변수1, 역1, 변수2, 역2 선언
	문자열로 입력받기. 2개 변수.
	for(3번) {
	string1_r[i] = string1[2-i]
	string2_r[i] = string2[2-i]
	}

	if(int(string1_r) > int(string2_r)
	cout << 1
	}
	else {
	cout << 2
	*/

	int max = -1;
	string s1, s1_r, s2, s2_r;

	cin >> s1;
	s1_r = s1;

	cin >> s2;
	s2_r = s2;

	for (int i = 0; i < 3; i++) {
		s1_r[i] = s1[2 - i];
		s2_r[i] = s2[2 - i];
	}

	if (stoi(s1_r) > stoi(s2_r)) {
		cout << s1_r;
	}
	else {
		cout << s2_r;
	}





	return 0;
}