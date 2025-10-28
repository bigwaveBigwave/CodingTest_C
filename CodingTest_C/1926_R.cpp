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
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {

	cin >> n >> m;

	//��� �Է� �ޱ�
	vector<vector<int>> v1(n, vector<int> (m));
	vector<vector<bool>> vis(n, vector<bool> (m, 0)); // ������ ���� �ʱⰪ 0���� �����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v1[i][j];
		}
	}

	int cnt = 0;// �׸��� ����
	int mx = 0;// ���� ū �׸��� ����
	//max�� ������ �ϸ� ǥ�� �Լ� �̸��ϰ� ��ġ�Ƿ� �ٲٱ�

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {//�� ĭ�� ��ȸ�Ͽ� ������ ã��
			if (v1[i][j] != 1 || vis[i][j]) continue;

			cnt++; // �� �׸� �߰�(��������)
			int area = 0; // �� �׸��� ����
			queue<pair<int, int>> q;
			q.push({ i, j });
			vis[i][j] = 1;//���� �� �湮 ǥ��

			while (!q.empty()) {
				area++;//�׸� ũ�� ����(ť���� ���� ĭ 1�� = ���� 1 ����)
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || v1[nx][ny] == 0) continue;
					vis[nx][ny] = 1;//�ߺ� ����
					q.push({ nx, ny });//������ ���� �̿�

				}
			}
			mx = max(mx, area);
		}
	}
	cout << cnt << "\n" << mx;
	
	
}

