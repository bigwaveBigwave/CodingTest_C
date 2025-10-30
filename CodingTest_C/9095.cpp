#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;


//1. 문제 해석 : 주어진 테스트 개수 개의 수가 1~3으로 만들어질 수 있는 방법의 수를 출력하기
//2. 손으로 풀기
/*
테스트 케이스 개수 입력받기
배열 선언
배열 초기 식 선언
테스트케이스 for문{
숫자입력받기


}

1. 테이블 정의하기
D[i] = i를 1,2,3의 합으로 나타내는 방법의 수

2. 점화식 찾기
D[i] = D[i-1] + D[i-2] + D[i-3]

3. 초기값 정하기
D[1] = 1
D[2] = 2
D[3] = 4

*/

int d[1000005];
int n, T;

int main() {
	ios::sync_with_stdio;
	cin.tie(nullptr);
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	//테이블을 바깥에서 미리 다 계산하기
	for (int i = 4; i < 11; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << d[n] << "\n";
	}
	
	return 0;
}