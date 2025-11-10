#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { 1, -1, 2, -2, 2, -2, 1, -1 }; 

int t, n;
int cnt = 0;//최소 이동 개수
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<vector<int>> v(n, vector<int> (n));
		vector<vector<int>> vis(n, vector<int>(n));
		int cx, cy;//현재 좌표
		int fx, fy;//지향 좌표
		cin >> cx >> cy;
		cin >> fx >> fy;
		queue<pair<int, int>> q;//매 테스트 케이스 마다 새로 생성(큐가 비어야되니까)

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				vis[i][j] = -1;
			}
		}
		vis[cx][cy] = 0;
		if (cx == fx && cy == fy) {
			cout << 0 << "\n";
			continue;//시작과 지향 좌표가 같으면 BFS 안 돌려도 되니까 continue(return은 프로그램을 바로 끝내버림)
		};
		q.push({ cx, cy });
		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			//cout << cur.first << ", " << cur.second << "// ";
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (vis[nx][ny] >= 0) continue;
				vis[nx][ny] = vis[cur.first][cur.second] + 1;
				q.push({ nx, ny });
			}
		}
		cout << vis[fx][fy] << "\n";
	}
	

	return 0;
}