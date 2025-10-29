#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
#define X first
#define Y second

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

//1. ���� �ؼ� : �־��� ��, ��, ���� ��ġ ������ ���� ���� ��ġ��
// �Է¹ް� �࿭�� ��ȯ�ؼ� 1�� ���ִ� �׷��� ������ ���ϱ�
//2. ������ Ǯ��
/*
�׽�Ʈ ���̽� ���� �Է¹ޱ�

��, ��, ������ġ ������ for������ �Է¹ޱ�
��, ���� �迭 �����
������ġ���� for������ ���� ��ġ�ε����� �Է¹ް� �ű�ٰ� 1 ����

�湮�迭�����
�湮 ť �����
�����¿� �迭 �����
ī��Ʈ ���� ����

0,0�������� floodfill,
while�� ���� �� ���� ī��Ʈ ����++;

1,1���� ���� Flood Fill ����
�湮�迭 �����
�湮 ť �����
�����¿� �迭 �����
*/

int main() {

	int T, M, N, K, cnt;
	int cnt = 0;
	int x, y;
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		vector<vector<int>> v(N, vector<int> (M));//�������迭�ణ �򰥸�
		while (K--) {
			cin >> x >> y;
			v[x][y] = 1;

		}
		vector<vector<int>> vis(N, vector<int>(M, 0));//�������迭�ణ �򰥸�
		queue<pair<int, int>> q1;//pair�����򰥸�

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				v[i][j] = 1;
				q1.push({ i, j });
				while (!q1.empty()) {
					pair<int, int> curr = q1.front(); q1.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = curr.X + dx[dir];
						int ny = curr.Y + dy[dir];
						//��ǥ ���� �����ų� ��, �� ������ ������ �̹� �ݺ����� �н�
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						//��ǥ ���� �̹� �湮�� ���̰ų�, ���߰� ���� ���̸� �̹� �ݺ����� �н�
						if (vis[nx][ny] || v[nx][ny] == 0) continue;
						vis[nx][ny] = 1; q1.push({ nx, ny });
					}

				}
				cnt++;
			}
		}

		cout << cnt;
		
		
	}

	
	

	return 0;
}