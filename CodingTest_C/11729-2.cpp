#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int from, int via, int to, ostringstream& out) {
    if (n == 1) {
        out << from << ' ' << to << '\n';
        return;
    }
    hanoi(n - 1, from, to, via, out);   // 1) n-1을 보조 기둥으로
    out << from << ' ' << to << '\n';   // 2) 가장 큰 원판 이동
    hanoi(n - 1, via, from, to, out);   // 3) n-1을 목적지로
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long moves = (1LL << n) - 1;   // n<=20이라 안전
    cout << moves << '\n';

    ostringstream out;
    hanoi(n, 1, 2, 3, out);
    cout << out.str();
    return 0;
}
