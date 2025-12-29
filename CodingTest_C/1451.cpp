#include <iostream>
using namespace std;
using ll = long long;

int N, M;
ll a[101][101];
ll ps[101][101];

ll sum(int x1, int y1, int x2, int y2) {
    return ps[x2][y2]
        - ps[x1 - 1][y2]
        - ps[x2][y1 - 1]
        + ps[x1 - 1][y1 - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            a[i][j] = s[j - 1] - '0';
            ps[i][j] = a[i][j] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
        }
    }

    ll ans = 0;

    // 1) 세로 3분할
    for (int i = 1; i <= M - 2; i++)
        for (int j = i + 1; j <= M - 1; j++) {
            ll A = sum(1, 1, N, i);
            ll B = sum(1, i + 1, N, j);
            ll C = sum(1, j + 1, N, M);
            ans = max(ans, A * B * C);
        }

    // 2) 가로 3분할
    for (int i = 1; i <= N - 2; i++)
        for (int j = i + 1; j <= N - 1; j++) {
            ll A = sum(1, 1, i, M);
            ll B = sum(i + 1, 1, j, M);
            ll C = sum(j + 1, 1, N, M);
            ans = max(ans, A * B * C);
        }

    // 3) 왼쪽 | (오른쪽 위 / 아래)
    for (int i = 1; i <= M - 1; i++)
        for (int j = 1; j <= N - 1; j++) {
            ll A = sum(1, 1, N, i);
            ll B = sum(1, i + 1, j, M);
            ll C = sum(j + 1, i + 1, N, M);
            ans = max(ans, A * B * C);
        }

    // 4) 오른쪽 | (왼쪽 위 / 아래)
    for (int i = 2; i <= M; i++)
        for (int j = 1; j <= N - 1; j++) {
            ll A = sum(1, i, N, M);
            ll B = sum(1, 1, j, i - 1);
            ll C = sum(j + 1, 1, N, i - 1);
            ans = max(ans, A * B * C);
        }

    // 5) 위 | (아래 왼쪽 / 오른쪽)
    for (int i = 1; i <= N - 1; i++)
        for (int j = 1; j <= M - 1; j++) {
            ll A = sum(1, 1, i, M);
            ll B = sum(i + 1, 1, N, j);
            ll C = sum(i + 1, j + 1, N, M);
            ans = max(ans, A * B * C);
        }

    // 6) 아래 | (위 왼쪽 / 오른쪽)
    for (int i = 2; i <= N; i++)
        for (int j = 1; j <= M - 1; j++) {
            ll A = sum(i, 1, N, M);
            ll B = sum(1, 1, i - 1, j);
            ll C = sum(1, j + 1, i - 1, M);
            ans = max(ans, A * B * C);
        }

    cout << ans << "\n";
}
