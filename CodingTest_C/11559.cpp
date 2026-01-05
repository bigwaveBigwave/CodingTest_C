#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//문제 해석
/*
뿌요들의 연쇄 터짐 갯수를 출력하기
조건 : 1. 뿌요는 4개 이상 상하좌우 연결돼있으면 한꺼번에 터짐
      2. 뿌요가 터지면 위 뿌요들이 내려옴
      3. 터지는 뿌요가 여러 개 있다면 연쇄터짐 갯수는 1이 증가함
*/
//구조화
/*
1. 12X6 입력받기
2. 같은 색이 상하좌우 4개 붙어있는지 확인
3-1. 붙어있으면 연쇄 터짐 갯수 1증가
3-2. 안 붙어있으면 0 출력
4. 터지고나면 윗 뿌요들을 아래로 내리기
*/
//수도코딩
/*
12x6 배열 선언, 입력받기
터짐 갯수 변수 선언(0초기화)
터짐 여부 bool 변수 선언(false 초기화)
방향 배열 선언(상하좌우)
배열반복{
.이 아닌 문자가 있는 곳 찾기
거기서 상하좌우가 같은 문자인지보고(bfs)
같으면서 터짐변수가 false면 터짐 횟수 증가
같으면서 터짐변수가 true면 터짐횟수 그대로
같은거 없으면 터짐 횟수 출력
}
터질거이제 없으면 위 뿌요들 내려오게

*/

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    vector<vector<char>> board(12, vector<char>(6));
    vector<vector<int>> visit(12, vector<int>(6, -1));
    queue<pair<int, int>> q;
    int boomCount = 0;
    bool boom = false;

    //배열 입력받기
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> board[i][j];
        }
    }

    //뿌요 존재하는 위치 찾기
    for (int i = 11; i >= 0; i--) {
        for (int j = 5; j >= 0; j--) {

            //뿌요 존재
            if (board[i][j] != '.' && visit[i][j] != 1) {
                contiousCount = 0;
                visit[i][j] = 1;
                q.push({ i,j });
                while (!q.empty()) {
                    pair<int, int> curr = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = curr.first + dx[dir];
                        int ny = curr.second + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
                        if (board[nx][ny] == '.' || visit[nx][ny] == 1) continue;
                        if (board[curr.front][curr.second] == board[nx][ny]) {
                            board[curr.front][curr.second] = '.';
                            contiousCount++;
                            visit[nx][ny] = 1;
                            q.push({ nx, ny });
                        }
                    }

                }
                if (contiousCount >= 4) {
                    if (boom == false) {
                        boom = true;
                        boomCount++;
                    }
                    else if (boom == true) {
                        contiunue;
                    }
                }
                else {
                    cout << boomCount;
                }

            }
            else if (board[i][j] == '.') {
                if (board[i - 1][j] != '.') {
                    board[i][j] = board[i - 1][j];
                }
            }
        }
    }

    return 0;
}