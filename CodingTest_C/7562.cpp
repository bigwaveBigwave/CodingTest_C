#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { 1, -1, 2, -2, 2, -2, 1, -1 }; 
queue<pair<int, int>> q;
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

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				vis[i][j] = -1;
			}
		}
		vis[cx][cy] = 0;
		if (cx == fx && cy == fy) {
			cout << 0;
			return 0;
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
		cout << vis[fx][fy] << " ";
	}
	

	return 0;
}