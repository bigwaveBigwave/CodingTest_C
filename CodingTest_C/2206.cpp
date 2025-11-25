#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<tuple>

using namespace std;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
//주어진 행렬의 0,0에서부터시작해서  N,M으로 가는 최단 경로를 출력하기
//조건 : 0인 곳만 갈 수 있음. 필요시 한번은 벽을 부술수있음. 시작칸과 끝나는칸도 개수 포함

int n, m;

vector<vector<int>> board;
//vector<vector<int>> dist(N, vector<int> (M));//최단거리배열

//dist[x][y][b] : (x, y)에 벽을 b번 부순 상태(0 또는 1)로 도착한 최단 거리
vector<vector<vector<int>>> dist;//최단거리배열


//맵 밖으로 나가면 true를 반환하는 함수
bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

int bfs() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j][0] = dist[i][j][1] = -1;
            //모든 거리를 -1로 초기화, "-1은 아직 한번도 방문 안 함"을 의미
        }
    }
    dist[0][0][0] = dist[0][0][1] = 1;
    queue<tuple<int, int, int>> q;
    q.push({ 0, 0, 0 });
    while (!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front();//tie를 써서 세 변수로 분해해서 받기
        if (x == n - 1 && y == m - 1) return dist[x][y][broken];
        q.pop();
        int nextdist = dist[x][y][broken] + 1;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (OOB(nx, ny)) continue;
            if (dist[nx][ny][broken] == -1 && board[nx][ny] == 0) {
                dist[nx][ny][broken] = nextdist;
                q.push({ nx, ny, broken });
            }

            if (!broken && board[nx][ny] == 1 && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = nextdist;
                q.push({ nx, ny, 1 });
            }
        }

    }
    return -1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    board.resize(n, vector<int>(m));
    dist.resize(n, vector<vector<int>>(m, vector<int>(2, 0)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    cout << bfs();


    return 0;
}
