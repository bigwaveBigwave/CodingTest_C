#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string cmd;
        cin >> cmd;

        int dir = 0;
        int x = 0, y = 0;

        int minX = 0, maxX = 0;
        int minY = 0, maxY = 0;

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
            else if(c == 'L') {
                dir = (dir + 3) % 4;

            }
            else if (c == 'R') {
                dir = (dir + 1) % 4;
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
