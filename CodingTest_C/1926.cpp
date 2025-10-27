#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<iomanip>
#include<string>
#include<utility>
using namespace std;
#define X first
#define Y second

int board[502][502] = 
{ {1,1,1,0,1,0,0,0,0,0},
  {1,0,0,0,1,0,0,0,0,0},
  {1,1,1,0,1,0,0,0,0,0},
  {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} };

bool vis[502][502];//해당 칸에 방문했는지 여부를 저장
int n = 7, m = 10;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };//상하좌우 네 방향을 의미


//주어진 행렬에서 1로 연결된 행렬의 개수와 행렬 크기의 최댓값 구하기

/*
<손으로 풀기>
1. 입력 행렬크기, 행렬 받기
2. 
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	
	vector<int> v1(n);
	queue<pair<int, int>> Q;
	vis[0][0] = 1; //(0, 0)을 방문했다고 명시
	Q.push({ 0,0 });
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		for (int dir = 0; dir < 4; dir++) { //  상하좌우 칸을 살펴볼 것이다.
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];//nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 밖일 경우 넘어감
			if (vis[nx][ny] || board[nx][ny] != 1) continue;//이미 방문한 칸이거나 파란 칸이 아닐 경우
			vis[nx][ny] = 1;//(nx, ny)를 방문했다고 명시
			Q.push({ nx, ny });


		}
	}

	for (int i = 0; i < n; i++) {
		cin >> v1[i];
	}
	sort(v1.begin(), v1.end());
	

	return 0;
}