#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int count = 0;
    vector<int> extent;
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> board(m, vector<int>(n));
    vector<vector<int>> dist(m, vector<int>(n));
    queue<pair<int, int>> q;//pair 문법
    //board를 1 또는 0 으로 채우기
    for (int i = 0; i < m; i++) {
        for (int j = 0; i < 2; j++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            for (int k = x1; k < x2; k++) {
                for (int l = y1; 1 < y2; l++) {
                    board[k][l] = 1;
                }
            }
        }
    }
    //BFS
    for (int p = 0; p < m; p++) {
        for (int r = 0; r < n; r++) {
            if (board[p][r] != 1) {
                dist[p][r] = 1;
                q.push({ p, r });
                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if (dist[nx][ny]  != 0 || board[nx][ny] == 1) continue;
                        dist[nx][ny] = 1;
                        q.push({ nx, ny });
                    }
                }
                count += 1;
                extent.push_back((nx + 1) * (ny + 1));
            }

        }
    }
    sort(extent.begin(), extent.end());
    cout << count << '\n';
    for (int t = 0; t < extent.size(); t++) {
        cout << extent[t] << " ";
    }


    return 0;
}