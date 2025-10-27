#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<iomanip>
#include<string>
#include<utility>
using namespace std;

//행렬의 1 묶음의 개수와 최대 묶음 크기를 구하기
//1. 행, 열, 행렬 입력받기
//2. 0,0부터 시작해서 주변의 1인 곳을 모두 찾고 크기를 배열에 넣기.
//3. 한 개 끝나면 count 변수 1 증가시키기

/*
int n, m, cnt, max
cin >> n >> m;
cnt = 0; -> 개수
max = 0; -> 크기
int arr[n][m]

arr 입력받기

vis[n][m]
큐<int, int> q;
반복문 한번 돌릴떄마다 개수 1 증가, 최댓값에 넣어서 크면 갱신, 작으면 안 갱신(그대로)
*/
#define X first
#define Y second

int n, m;
int cnt = 0;
int max = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
queue<pair<int, int>> q;

int main() {
	cin >> n >> m;
	vector<vector<int>> v1(n, vector<int> (m));
	vector<vector<bool>> vis(n, vector<bool> (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v1[i][j];
			vis[i][j] = 0;
		}
	}

	vis[0][0] = 1;
	q.push({ 0, 0 });
	vis[0][0] = 1;
	while(!q.empty()) {
		pair<int, int> curr = q.front(); q.pop();
		cout << "(" << curr.first << ")" << ", " << curr.second << ")" << " ->";
		for (int dir = 0; dir < 4; dir++) {
			int nx = curr.X + dx[dir];
			int ny = curr.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || v1[nx][ny] == 0) continue;
			q.push({ nx, ny });
			vis[nx][ny] = 1;
			

		}

	}
	
}

