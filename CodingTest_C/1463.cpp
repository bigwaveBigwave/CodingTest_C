#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
#define X first
#define Y second

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

//1. 문제 해석 : 주어진 행, 열, 배추 위치 개수와 배추 존재 위치를
// 입력받고 행열로 변환해서 1이 모여있는 그룹의 개수를 구하기
//2. 손으로 풀기
/*
테스트 케이스 개수 입력받기

행, 열, 배추위치 개수를 for문에서 입력받기
행, 열로 배열 만들기
배추위치개수 for문에서 배추 위치인덱스를 입력받고 거기다가 1 대입

방문배열만들기
방문 큐 만들기
상하좌우 배열 만들기
카운트 변수 선언

0,0에서부터 floodfill,
while문 돌릴 때 마다 카운트 변수++;

1,1에서 부터 Flood Fill 시작
방문배열 만들기
방문 큐 만들기
상하좌우 배열 만들기
*/

int d[1000005];
int n;

int main() {
	cin >> n;
	d[1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
		if (i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);

	}
	cout << d[n];
	return 0;
}