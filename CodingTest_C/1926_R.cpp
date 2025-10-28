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
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {

	cin >> n >> m;

	//행렬 입력 받기
	vector<vector<int>> v1(n, vector<int> (m));
	vector<vector<bool>> vis(n, vector<bool> (m, 0)); // 이차원 벡터 초기값 0으로 만들기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v1[i][j];
		}
	}

	int cnt = 0;// 그림의 개수
	int mx = 0;// 가장 큰 그림의 넓이
	//max를 변수로 하면 표준 함수 이름하고 겹치므로 바꾸기

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {//전 칸을 순회하여 시작점 찾기
			if (v1[i][j] != 1 || vis[i][j]) continue;

			cnt++; // 새 그림 발견(개수세기)
			int area = 0; // 각 그림의 넓이
			queue<pair<int, int>> q;
			q.push({ i, j });
			vis[i][j] = 1;//시작 전 방문 표시

			while (!q.empty()) {
				area++;//그림 크기 세기(큐에서 꺼낸 칸 1개 = 넓이 1 증가)
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || v1[nx][ny] == 0) continue;
					vis[nx][ny] = 1;//중복 방지
					q.push({ nx, ny });//다음에 꺼낼 이웃

				}
			}
			mx = max(mx, area);
		}
	}
	cout << cnt << "\n" << mx;
	
	
}

