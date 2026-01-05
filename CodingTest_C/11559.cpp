#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
/*

1 )핵심 : 라운드 반복

- 한 라운드에서 할 일
1. 현재 보드에서 터질 그룹들 찾기
2. 터질 그룹이 있으면 한꺼번에 제거
3. 제거 후 중력 적용
4. 이 라운드에서 한 번이라도 터졌으면 -> 연쇄 + 1

더이상 터질 그룹이 없으면 종료


- 전체 구조
while(true)
터질 것 찾기
없으면 break
제거
중력
answer++

2) 터질 그룹 찾기의 구조
상태
- 보드
- 방문배열
- bfs로 같은 색 연결 컴포넌트 찾기

bfs한번의 결과로 얻는 것
- 같은 색으로 연결된 칸 목록 cells
- cells.size() >= 4면 이 그룹은 터진다

중요 : 찾는 단계에서는 보드를 건드리면 안 됨
=> 탐색과 제거는 분리하기
3) 제거의 구조
- 터질 그룹들의 칸들을 전부 .으로 바꿈
- 한 라운드에 여러 그룹이 터져도 연쇄는 +1만 함.(라운드마다 poppedThisRound boolean이 필요)

4) 중력의 구조(열단위처리)
각 열에 대해 :
아래에서 위로 스캔하면서 뿌요를 모아 아래로 채운다.
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<char>> board(12, vector<char>(6));
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> board[i][j];
        }
    }

    int chain = 0;

    while (true) {
        vector<vector<int>> visited(12, vector<int>(6, 0));
        bool poppedThisRound = false;

        // 1. 터질 그룹 찾기 + 제거 표시 / 실행
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (board[i][j] == '.' || visited[i][j]) continue;

                char color = board[i][j];
                queue<pair<int, int>> q;
                vector<pair<int, int>> cells;

                visited[i][j] = 1;
                q.push({ i, j });
                cells.push_back({ i, j });

                //bfs로 같은 색 그룹 찾기
                while (!q.empty()) {
                    pair<int, int> curr = q.front(); q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = curr.first + dx[dir];
                        int ny = curr.second + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
                        if (visited[nx][ny]) continue;
                        if (board[nx][ny] != color) continue;

                        visited[nx][ny] = 1;
                        q.push({ nx, ny });
                        cells.push_back({ nx, ny });
                    }
                }

                //4개 이상이면 제거
                if ((int)cells.size() >= 4) {
                    poppedThisRound = true;
                    for (auto& p : cells) {
                        board[p.first][p.second] = '.';
                    }
                }
            }
        }
        //이번 라운드에 터진 게 없으면 종료
        if (!poppedThisRound) break;

        //연쇄 +1
        chain++;

        //2. 중력 적용(열 단위)
        for (int c = 0; c < 6; c++) {
            int write = 11;//다음 뿌요가 떨어질 위치
            for (int r = 11; r >= 0; r--) {//아래에서 위로 스캔
                if (board[r][c] != '.') {//뿌요가 있으면 -> 떨어뜨릴 대상
                    board[write][c] = board[r][c];//떨어뜨리기
                    if (write != r) {//원래 자리는 비우기
                        board[r][c] = '.';

                    }
                    write--;//포인터 이동
                }

            }
                //정리 안 된 위쪽 구간을 전부 빈 칸으로 초기화
                for (int r = write; r >= 0; r--) board[r][c] = '.';
            
        }

    }
    cout << chain << "\n";

    return 0;
}