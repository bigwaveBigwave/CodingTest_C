#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define X first
#define Y second

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
	int w, h, t;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> w >> h;
		vector<vector<char>> board(h, vector<char> (w));
		vector<vector<int>> visit_s(h, vector<int>(w));
		vector<vector<int>> visit_f(h, vector<int>(w));
		queue<pair<int, int>> Q_s;
		queue<pair<int, int>> Q_f;
		//불의 방문 배열
		// 벽(#) : -1, 못감
		// 상근(@) : 0, 갈 수 있음
		// 길(.) : 0, 갈수있음
		// 불(*) : 1, 현재 위치(다시 안 옴)
		// 
		// 상근이의 방문배열
		// 벽(#) : -1
		// 상근(@) : 1, 현재 위치(다시 안 옴)
		// 길(.) : 0, 갈수있음
		// 불(*) : 이제 위치하게되는 곳은 못감(-1) / 지금 있거나 지나간 곳은 갈 수 있음(0)

		//상근이가 행이나 열의 범위를 넘어서면 탈출 완료
		//
		//불이 상근이를 잡아먹으면 탈출 불가
		//
		//둘이 안 마주치면 BFS 계속
		for (int i = 0; i < h; i++) {
			
			cin >> s;
			for (int j = 0; j < w; j++) {
				char k = s[j];
				board[i][j] = k;
				//상근이가 위치한 곳(1)
				if (k == '@') {
					int sx = i;
					int sy = j;
					visit_s[i][j] = 1;
					Q_s.push({ i, j });
				}
			   //불이 위치한 곳(1)
				else if (k == '*') {
					int fx = i;
					int fy = j;
					visit_s[i][j] = -1;
					visit_f[i][j] = 1;
					Q_f.push({ i, j });
				}
				//벽이어서 갈 수 없는 곳(-1)
				else if (k == '#') {
					visit_s[i][j] = -1;
					visit_f[i][j] = -1;
				}
				//그 외 '.' 은 갈 수 있는 곳(0)
			}
			while (Q_s.front() == Q_f.front()) {
				pair<int, int> cur_s = Q_s.front(); Q_s.pop();
				pair<int, int> cur_f = Q_f.front(); Q_f.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur_s.X + dx[dir];
					int ny = cur_s.Y + dy[dir];
					int nx_f = cur_f.X + dx[dir];
					int ny_f = cur_f.Y + dy[dir];
					if (nx < 0 || ny < 0 || nx_f < 0 || ny_f<0 || nx_f >= w || ny_f >= h) {
						continue;
					}
					if (visit_s[nx][ny] == -1/*벽(상근)*/ || visit_s[nx][ny] == 1/*지금 있는 위치(상근)*/ ||
						visit_f[nx][ny] == -1/*벽(불)*/ || visit_f[nx][ny] == 1/*지금 있는 위치(불)*/) {
						continue;
					}
					if (nx >= w || ny >= h) {
						cout << visit_s[nx][ny] << "\n";
						break;
					}

					visit_s[nx][ny] = visit_s[cur_s.X][cur_s.Y] + 1;
					Q_s.push({ nx, ny });
				}
				cout << "IMPOSSIBLE" << "\n";
			}
		}
	}
	


	return 0;
}