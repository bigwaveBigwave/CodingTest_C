#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };


int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M));
	vector<vector<int>> dist(N, vector<int>(M, -1));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	int answer = 0;
	vector<int> maxValue;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1 && dist[i][j] == -1) {//방문 안 한 곳만 bfs
				dist[i][j] = 0;//시작점 거리
				q.push({ i, j });
				int cnt = 1;//섬크기
				while (!q.empty()) {
					pair<int, int> curr = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = curr.first + dx[dir];
						int ny = curr.second + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) {//N-1, M-1까지만 배열임
							continue;
						}
						if (dist[nx][ny] != -1 || board[nx][ny] == 0) {
							continue;
						}
						dist[nx][ny] = dist[curr.first][curr.second] + 1;
						q.push({ nx, ny });
						cnt++;
					}
				}
				answer = max(answer, cnt);

			}
			
		}
	}

	
	
	cout << answer;

	return 0;
}