#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define X first
#define Y second

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

//1. 문제 해석 : 주어진 행렬의 1,1 위치에서 N, M 위치까지 가는 최소 칸 수 구하기
//2. 손으로 풀기
/*
입력받기

1,1에서 부터 Flood Fill 시작
방문배열 만들기
방문 큐 만들기
상하좌우 배열 만들기
*/

int main() {

	int N, M, cnt;
	cin >> N >> M;
	cnt = 0;

	// 1. 행렬 입력 받을 시 공백 여부 잘 확인!
	// 공백 없이 0/1이 주어지므로 문자열로 받기
	vector<string> grid(N);
	for (int i = 0; i < N; i++) {
		cin >> grid[i];
	}

	//이차원 벡터의 열을 0으로 채우기
	vector<vector<int>> dist(N, vector<int>(M, 0));
	queue<pair<int, int>> q1;

	// 2. 시작점 0, 0 세팅
	dist[0][0] = 1;
	q1.push({ 1,1 });
	

	while (!q1.empty()) {
		pair<int, int> curr = q1.front(); q1.pop();//3. pop은 한 번
		for (int dir = 0; dir < 4; dir++) {
			int nx = curr.X + dx[dir];
			int ny = curr.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				continue;
			}
			if (dist[nx][ny] || grid[nx][ny] == 0) {
				continue;
			}
			
			dist[nx][ny] = dist[curr.X][curr.Y] + 1;//최단거리 갱신
			q1.push({ nx, ny });
			
		}
		
	}

	cout << dist[N-1][M-1];
	


	



	return 0;
}