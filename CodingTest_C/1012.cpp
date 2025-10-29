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

int main() {

	int T, M, N, K, cnt;
	int cnt = 0;
	int x, y;
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		vector<vector<int>> v(N, vector<int> (M));//이차원배열약간 헷갈림
		while (K--) {
			cin >> x >> y;
			v[x][y] = 1;

		}
		vector<vector<int>> vis(N, vector<int>(M, 0));//이차원배열약간 헷갈림
		queue<pair<int, int>> q1;//pair선언헷갈림

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				v[i][j] = 1;
				q1.push({ i, j });
				while (!q1.empty()) {
					pair<int, int> curr = q1.front(); q1.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = curr.X + dx[dir];
						int ny = curr.Y + dy[dir];
						//좌표 값이 음수거나 행, 열 범위를 넘으면 이번 반복문은 패스
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						//좌표 값이 이미 방문한 값이거나, 배추가 없는 곳이면 이번 반복문은 패스
						if (vis[nx][ny] || v[nx][ny] == 0) continue;
						vis[nx][ny] = 1; q1.push({ nx, ny });
					}

				}
				cnt++;
			}
		}

		cout << cnt;
		
		
	}

	
	

	return 0;
}