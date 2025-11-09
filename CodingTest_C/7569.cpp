#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
#define X first
#define Y second
#define Z third
//1의 상하좌우 위 아래의 0들을 1로 바꾸고 모두 1이 되는 날을 출력하라
int d = 0; // 걸리는 일 수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, h;
	cin >> n >> m >> h;

	int board[200][200][200];
	int vis[200][200][200];
	queue<tuple<int, int, int>> q;

	int dx[] = { -1, 0, 1, 0, 0, 0 };
	int dy[] = { 0, 1, 0, -1, 0, 0 };
	int dz[] = { 0, 0, 0, 0, 1, -1 };

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[k][i][j];
			}
		}
	}
	//1인 곳만 방문하는 과정
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[k][i][j] == 1) {
					continue;
				}
				if (board[k][i][j] == 1) {
					vis[k][i][j] = 1;


					q.push({ k, i, j });
					while (!q.empty()) {
						tuple<int, int, int> cur = q.front(); q.pop();
						d++;
						//인접한 여섯방향이 범위안에 맞고 방문 안 했고 -1이 아니면 (1이면 방문, 0이면 인접방향을 모두 1로 바꾼 후 일수를 +1하고 방문)
						for (int dir = 0; dir < 6; dir++) {
							int nx = get<1>(cur) + dx[dir];
							int ny = get<2>(cur) + dy[dir];
							int nz = get<0>(cur) + dz[dir];
							if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
							if (vis[nz][nx][ny] == 1 || board[nz][nx][ny] < 0) continue;
							if (board[nz][nx][ny] == 0) {
								board[nz][nx][ny] = 1;
								vis[nz][nx][ny] = 1;
								q.push({ nz, nx, ny });
							}
							vis[nz][nx][ny] = 1;
							q.push({ nz, nx, ny });
						}
					}
				}
				
				
			}
		}
	}
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[k][i][j] == 1) {
					cout << d;
				}
				cout << -1;
				
			}
		}
	}

	return 0;
}