#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<char>> board(N, vector<char> (N));
	queue<pair<int, int>> q;
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};
	vector<vector<char>> visit(N, vector<char> (N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
		
	}

	int cnt = 0;
	int cnt_2 = 0;
	visit[0][0] = 1;
	q.push({0,0});
	cnt++;
	cnt_2++;
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (visit[nx][ny] == 1) continue;
			visit[nx][ny] = 1;
			q.push({ nx, ny });
			if (board[nx][ny] != board[cur.first + dx[dir - 1]][cur.second + dy[dir - 1]]) {
				cnt++;
				if ((board[nx][ny] == 'R' && board[cur.first + dx[dir - 1]][cur.second + dy[dir - 1]] == 'G') ||
					(board[nx][ny] == 'G' && board[cur.first + dx[dir - 1]][cur.second + dy[dir - 1]] == 'R')) {
					continue;
				}
				cnt_2++;
			}
		}
	}
	cout << cnt << ' ' <<  cnt_2;


	return 0;
}