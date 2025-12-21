#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string cmd;
        cin >> cmd;

        // 방향: 0=북, 1=동, 2=남, 3=서
        int dir = 0;
        int x = 0, y = 0;

        int minX = 0, maxX = 0;
        int minY = 0, maxY = 0;

        // dx, dy: dir 기준 이동
        int dx[4] = { 0, 1, 0, -1 };
        int dy[4] = { 1, 0, -1, 0 };

        for (char c : cmd) {
            if (c == 'F') {
                x += dx[dir];
                y += dy[dir];
            }
            else if (c == 'B') {
                x -= dx[dir];
                y -= dy[dir];
            }
            else if (c == 'L') {
                dir = (dir + 3) % 4;   // 왼쪽 회전
            }
            else if (c == 'R') {
                dir = (dir + 1) % 4;   // 오른쪽 회전
            }

            minX = min(minX, x);
            maxX = max(maxX, x);
            minY = min(minY, y);
            maxY = max(maxY, y);
        }

        int width = maxX - minX;
        int height = maxY - minY;
        cout << width * height << '\n';
    }

    return 0;
}
