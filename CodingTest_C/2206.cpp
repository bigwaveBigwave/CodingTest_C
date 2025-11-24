#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
//주어진 행렬의 0,0에서부터시작해서  N,M으로 가는 최단 경로를 출력하기
//조건 : 0인 곳만 갈 수 있음. 필요시 한번은 벽을 부술수있음. 시작칸과 끝나는칸도 개수 포함
int main() {
    int N, M;
    int answer = 0;//최단경로거리
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int> (M));
    vector<vector<int>> dist(N, vector<int> (M));//최단거리배열
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        string a;
        cin >> a;//getline은 줄 전체를 문자열로 읽음(cin은 단어 단위)
        for (int j = 0; j < M; j++) {
            board[i][j] = a[j];
        }

    }
    dist[0][0] = 1;
    answer = 1;
    q.push({ 0, 0 });
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx > N || ny < 0 || ny > M) continue;
            if (dist[nx][ny] == 1 || board[nx][ny] == 1) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({ nx, ny });
            answer += 1;
        }

    }
    return 0;
}