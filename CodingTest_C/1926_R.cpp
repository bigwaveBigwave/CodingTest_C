#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<iomanip>
#include<string>
#include<utility>
using namespace std;

//����� 1 ������ ������ �ִ� ���� ũ�⸦ ���ϱ�
//1. ��, ��, ��� �Է¹ޱ�
//2. 0,0���� �����ؼ� �ֺ��� 1�� ���� ��� ã�� ũ�⸦ �迭�� �ֱ�.
//3. �� �� ������ count ���� 1 ������Ű��

/*
int n, m, cnt, max
cin >> n >> m;
cnt = 0; -> ����
max = 0; -> ũ��
int arr[n][m]

arr �Է¹ޱ�

vis[n][m]
ť<int, int> q;
�ݺ��� �ѹ� ���������� ���� 1 ����, �ִ񰪿� �־ ũ�� ����, ������ �� ����(�״��)
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

