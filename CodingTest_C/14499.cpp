#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, x, y, K;
    cin >> N >> M >> x >> y >> K;

    vector<vector<int>> board(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    // dice indices:
    // 0: top, 1: bottom, 2: north, 3: south, 4: west, 5: east
    int dice[6] = { 0, 0, 0, 0, 0, 0 };

    // direction: 1 east, 2 west, 3 north, 4 south
    int dx[5] = { 0, 0, 0, -1, 1 };
    int dy[5] = { 0, 1, -1, 0, 0 };

    while (K--) {
        int dir;
        cin >> dir;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // out of bounds -> ignore
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        // roll dice
        int top = dice[0], bottom = dice[1], north = dice[2], south = dice[3], west = dice[4], east = dice[5];

        if (dir == 1) { // east
            dice[0] = west;
            dice[1] = east;
            dice[4] = bottom;
            dice[5] = top;
            // north/south unchanged
            dice[2] = north;
            dice[3] = south;
        }
        else if (dir == 2) { // west
            dice[0] = east;
            dice[1] = west;
            dice[4] = top;
            dice[5] = bottom;
            dice[2] = north;
            dice[3] = south;
        }
        else if (dir == 3) { // north
            dice[0] = south;
            dice[1] = north;
            dice[2] = top;
            dice[3] = bottom;
            dice[4] = west;
            dice[5] = east;
        }
        else if (dir == 4) { // south
            dice[0] = north;
            dice[1] = south;
            dice[2] = bottom;
            dice[3] = top;
            dice[4] = west;
            dice[5] = east;
        }

        // move
        x = nx; y = ny;

        // copy between dice bottom and board cell
        if (board[x][y] == 0) {
            board[x][y] = dice[1];
        }
        else {
            dice[1] = board[x][y];
            board[x][y] = 0;
        }

        // print top
        cout << dice[0] << "\n";
    }

    return 0;
}
