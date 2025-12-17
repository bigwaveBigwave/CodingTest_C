#include<iostream>
#include<queue>
using namespace std;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };


int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M));
	vector<vector<int>> dist(N, vector<int>(M));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	vector<int> maxValue;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1) {
				dist[i][j] = 1;
				q.push({ i, j });
				int maxV = 0;
				while (!q.empty()) {
					pair<int, int> curr = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = curr.first + dx[dir];
						int ny = curr.second + dy[dir];
						if (nx < 0 || nx > N || ny < 0 || ny > M) {
							continue;
						}
						if (dist[nx][ny] != 0 || board[nx][ny] == 0) {
							continue;
						}
						dist[nx][ny] = dist[curr.first][curr.second] + 1;
						q.push({ nx, ny });
						maxV++;
					}
				}
				maxValue.push_back(maxV);

			}
			
		}
	}

	int answer = 0;
	for (int v = 0; v < maxValue.size(); v++) {
		if (maxValue[v] > answer) {
			answer = maxValue[v];
		}

	}
	cout << answer;

	return 0;
}