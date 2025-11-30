#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
    int n;
    int count = 0;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> dist(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j] - '0';
        }
    }
    queue<pair<int, int>> q;
    vector<int> e;

    for (int p = 0; p < n; p++) {
        for (int k = 0; k < n; k++) {
            if (board[p][k] != 0 && dist[p][k] == 0) {
                dist[p][k] = 1;
                q.push({ p, k });
                int home = 0;
                count++;
                
                while (!q.empty()) {
                    pair<int, int> curr = q.front(); q.pop();
                    home++;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = curr.first + dx[dir];
                        int ny = curr.second + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (dist[nx][ny] > 0 || board[nx][ny] == 0)  continue;
                        dist[nx][ny] = 1;
                        q.push({ nx, ny });
                    }
                }
                
                e.push_back(home);
            }
        }
    }
    cout << count << "\n";
    sort(e.begin(), e.end());
    for (auto m : e) {
        cout << m << "\n";
    }
    return 0;
}