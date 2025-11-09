#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
int dx[] = { -1, 0, 1, 0, 0, 0 };
int dy[] = { 0, 1, 0, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };
int board[200][200][200];
int dist[200][200][200];
queue<tuple<int, int, int>> q;
int n, m, h;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	
	cin >> m >> n >> h;
	//익은 토마토 방문하기
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int tmp;
				cin >> tmp;
				board[i][j][k] = tmp;
				if (tmp == 1) q.push({ i, j, k });//익은 토마토
				if (tmp == 0) dist[i][j][k] = -1;//안 익은 토마토
			}
		}
	}
	
	//익은 토마토에서 인접한 안 익은 토마토를 익히고 거리배열에 +1 해서 일수 표현하기
	while (!q.empty()) {
		tuple<int, int, int> cur = q.front(); q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int nz = get<2>(cur) + dz[dir];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
			if (dist[nx][ny][nz] >= 0) continue;//아직 익지 않은 토마토면 현재 방문하고있는 위치 + 1
			dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			q.push({ nx, ny, nz });
		}

	}


	//최소일수 구하기
	int ans = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dist[k][i][j] == -1) {
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[i][j][k]);
				
			}
		}
	}

	cout << ans;

	return 0;
}