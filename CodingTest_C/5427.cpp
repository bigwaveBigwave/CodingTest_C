#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define X first
#define Y second

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	while (T--) {
		int w, h;
		cin >> w >> h;
		vector<string> board(h);
		for (int i = 0; i < h; i++) {
			cin >> board[i];
		}

		//dist_fire, dist_sang : -1 = 안 도달
		vector<vector<int>> dist_fire(h, vector<int>(w, -1));
		vector<vector<int>> dist_sang(h, vector<int>(w, -1));
		queue<pair<int, int>> qf;
		queue<pair<int, int>> qs;

		//초기 위치 세팅
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '*') {
					dist_fire[i][j] = 0;
					qf.push({ i, j });
				}
				else if (board[i][j] == '@') {
					dist_sang[i][j] = 0;
					qs.push({ i, j });
				}
			}
		}

		// 1) 불 전파 BFS(멀티소스)
		while (!qf.empty()) {
			auto cur = qf.front(); qf.pop();
			int cx = cur.first, cy = cur.second;
			for (int dir = 0; dir < 4; dir++) {
				int nx = cx + dx[dir], ny = cy + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (board[nx][ny] == '#') continue;//벽
				if (dist_fire[nx][ny] != -1) continue;//이미 전파된 자리
				dist_fire[nx][ny] = dist_fire[cx][cy] + 1;
				qf.push({ nx, ny });
			}
		}

		//2 ) 상근이 BFS(불 시간과 비교)
		bool escaped = false;
		int answer = -1;
		//큐가 비어있지 않으면서 아직 탈출하지 않았으면 반복분을 계속 수행한다
		while (!qf.empty() && !escaped) {
			auto cur = qs.front(); qs.pop();
			int cx = cur.first, cy = cur.second;
			for (int dir = 0; dir < 4; dir++) {
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];
				//범위를 벗어나면 탈출 성공(현재 위치 시간 +1)
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					escaped = true;
					answer = dist_sang[cx][cy] + 1;
					break;
				}
				if (board[nx][ny] == '#') continue;
				if (dist_sang[nx][ny] != -1) continue; // 이미 방문
				int nextTime = dist_sang[cx][cy] + 1;
				//불이 도달하, 상근이 먼저 도착할 수 있어야함
				if (dist_fire[nx][ny] != -1 && nextTime >= dist_fire[nx][ny]) continue;
				dist_sang[nx][ny] = nextTime;
				qs.push({ nx, ny });
			}

		}

		if (escaped) {
			cout << answer << '\n';
		}
		else {
			cout << "IMPOSSIBLE" << '\n';
		}
	}
	


	return 0;
}