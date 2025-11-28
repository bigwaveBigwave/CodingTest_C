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
    vector<vector<int>> board(m, vector<int>(n, 0));
    vector<vector<int>> dist(m, vector<int>(n, 0));
    queue<pair<int, int>> q;//pair 문법
    //board를 1 또는 0 으로 채우기
    for (int i = 0; i < k; i++) {
        
            int y1, x1, y2, x2;
            cin >> x1 >> y1 >> x2 >> y2; // 입력은 문제 그대로!
            for (int w = y1; w < y2; w++) {
                for (int l = x1; l < x2; l++) {
                    board[w][l] = 1;
                }
            }
        
    }

    
    //BFS
    for (int p = 0; p < m; p++) {
        for (int r = 0; r < n; r++) {
            if (board[p][r] != 1 && dist[p][r] == 0) {//bfs 시작 조건 추가(방문안했고 벽아닌곳)
                dist[p][r] = 1;
                int width = 1;
                q.push({ p, r });
                count++;
                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if (dist[nx][ny] > 0 || board[nx][ny] == 1) continue;
                        dist[nx][ny] = (nx + 1) * (ny + 1);
                        q.push({ nx, ny });
                        width++;
                    }
                }
                
                //넓이 계산 잘못됨
                extent.push_back(width);
            }

        }
    }
    sort(extent.begin(), extent.end());//오름차순
    cout << count << '\n';
    for (int t = 0; t < extent.size(); t++) {
        cout << extent[t] << " ";
    }


    return 0;
}