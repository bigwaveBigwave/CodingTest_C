#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define X first
#define Y second

//1. ���� �ؼ� : �־��� ����� 1,1 ��ġ���� N, M ��ġ���� ���� �ּ� ĭ �� ���ϱ�
//2. ������ Ǯ��
/*
�Է¹ޱ�

1,1���� ���� Flood Fill ����
�湮�迭 �����
�湮 ť �����
�����¿� �迭 �����
*/

int main() {

	int N, M, cnt;
	cin >> N >> M;
	cnt = 0;

	vector<vector<int>> v1(N, vector<int>(M));
	vector<vector<int>> vis1(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v1[i][j];
			vis1[i][j] = 0;
		}
	}

	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	queue<pair<int, int>> q1;

	q1.push({ 1,1 });
	vis1[1][1] = 1;
	cout << " ��¼��� !!!";

	while (!q1.empty()) {
		for (int dir = 0; dir < 4; dir++) {
			pair<int, int> curr = q1.front(); q1.pop();
			int nx = curr.X + dx[dir];
			int ny = curr.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				continue;
			}
			if (vis1[nx][ny] || v1[nx][ny] == 0) {
				continue;
			}
			q1.push({ nx, ny });
			vis1[nx][ny] = 1;
			cnt++;
		}
		
	}

	cout << cnt;
	


	



	return 0;
}