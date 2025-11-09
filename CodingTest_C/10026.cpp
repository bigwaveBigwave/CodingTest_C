#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define X first
#define Y second
char board[101][101];
bool vis[101][101];
int n;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1,0, 1 };

//영역에 속한 모든 칸을 방문 처리
void bfs(int i, int j) {
	queue<pair<int, int>> Q;
	Q.push({ i, j });
	vis[i][j] = 1;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;
			vis[nx][ny] = 1;
			Q.push({ nx, ny });
		}
	}
}

//아직 방문되지 않은 칸이 되면 영역의개수를 올림
int area() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j]) {
				cnt++;
				bfs(i, j);
			}
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int not_g = area();//적록 색약이 아닌 사람

	//적록색약인 사람을 구하기 위한 방문 배열 초기화
	for (int i = 0; i < n; i++) {
		fill(vis[i], vis[i] + n, false);
	}

	// 적록색약은 초록과 빨강을 구분 못하므로 초록이면 빨강으로바꿔줌
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G') {
				board[i][j] = 'R';
			}
		}
	}

	int is_g = area();
	cout << not_g << " " << is_g;
	return 0;
}