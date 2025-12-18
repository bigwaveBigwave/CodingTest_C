/*
문제 해석 : 모든 칸에서 시작해서 DFS로 5번 이동(=총 6칸 방문)하며 숫자를 붙이고, 나온 문자열을 set에 넣는다.

*/
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int board[5][5];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

set<string> st;

void dfs(int x, int y, int depth, string s) {
    if (depth ==  6) {
        st.insert(s);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        dfs(nx, ny, depth + 1, s + char('0' + board[nx][ny]));
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            string s;
            s += char('0' + board[i][j]);
            dfs(i, j, 1, s);
        }
    }
    cout << st.size() << "\n";
}