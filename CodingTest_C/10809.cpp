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
	 
	1. 문제해석
	각 알파벳마다 존재하면 시작 인덱스의 위치를, 없으면 -1을 출력하라
	
	2. 손으로 풀기

	알파벳 배열, -1로 초기화
	알파벳 입력
	알파벳 인덱스랑 알파벳 배열을 이중포문 돌리기
	만약 알파벳이 있으면
	   알파벳의 위치 인덱스를 배열에 -1대신 집어넣기
	만약 알파벳이 없으면
	   -1 그대로 두기

	알파벳 배열 출력

	3. psuedo code

	벡터<int> 모두 -1로, 26개 선언
	알파벳 문자열 입력받기

	for(i, 문자열 길이)
	  for(j, 알파벳 배열 크기)
	    if(문자열[i] == 알파벳배열[j]) {
		   알파벳 배열[j] = i
		   }

		   알파벳 배열 출력
	*/
	
	string words;
	cin >> words;
	vector<int> v1(26, -1);

	for (int i = 0; i < words.length(); i++) {
		int idx = words[i] - 'a';

			
			if (v1[idx] == -1) {
				v1[idx] = i;
			}
		
		
	}

	for (int i = 0; i < 26; i++) {
		cout << v1[i] << (i == 25 ? '\n' : ' ');
	}

	



	return 0;
}