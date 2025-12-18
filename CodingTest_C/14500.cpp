#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
//문제해석
/*
정사각형 네개가 이어져서 만들어진 테트로미노를 숫자판 위에 올려놓았을 때(회전, 대칭 가능),
그 4개의 숫자의 합의 최댓값을 구하라
*/

//수도코드 1
/*
종이의 크기 N, M 입력받기
종이 벡터 선언
방문 벡터 선언
가장 큰 값 주변의 가장 큰 수들로만 세 수를 탐색해서 그 합을 구하기. -- 1)
1 - 1) 가장 큰 수의 좌표값 저장하기
1 - 2) 가장 큰 수의 주변에서 BFS 세 번 돌리기
1 - 3) 각 최댓값의 위치에서 BFS를 돌리면 값이 계속 나올텐데 그 중 최댓값을 계속 갱신하기.
*/



int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
int maxValue = 0;//숫자판의 최댓값
int answer = 0;//목표인 최댓값
vector<vector<int>> board;
vector<vector<bool>> visit;

void dfs(int x, int y, int depth, int sum) {
    if (sum + (4 - depth) * maxValue <= answer) return;

    if (depth == 4) {
        answer = max(answer, sum);
        return;
    }
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (visit[nx][ny] == 1) {
            continue;
        }

        visit[nx][ny] = true;
        dfs(nx, ny, depth + 1, sum + board[nx][ny]);
        visit[nx][ny] = false;
    }
}

void checkT(int x, int y) {
    int center = board[x][y];
    int neighborSum = 0;
    int cnt = 0;
    int mn = INT_MAX;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        cnt++;
        neighborSum += board[nx][ny];
        mn = min(mn, board[nx][ny]);
    }

    if (cnt >= 3) {
        if (cnt == 4) {
            answer = max(answer, center + (neighborSum - mn));

        }
        else
            answer = max(answer, center + neighborSum);
    }

}
int main() {
    cin >> N >> M;
    board.resize(N, vector<int>(M));
    visit.resize(N, vector<bool>(M, false));
    //vector<pair<int, int>> maxValueSearch;
    //queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            maxValue = max(maxValue, board[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visit[i][j] = true;
            dfs(i, j, 1, board[i][j]);//시작 칸 포함 -> depth = 1
            visit[i][j] = false;

            checkT(i, j);
        }
    }
    cout << answer << "\n";

    return 0;
}