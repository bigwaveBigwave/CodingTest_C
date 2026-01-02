#include<iostream>
using namespace std;
int answer = 0;//이동 횟수의 최솟값
int loc = 0;//현재 위치
int dist = 0;//이동 거리

int solution(int x, int y) {

    long long d = y - x;
    long long m = (long long)sqrt((long double)d);

    if (m * m == d) return (int)(2 * m - 1);
    if (d <= m * m + m) return (int)(2 * m);
    return (int)(2 * m + 1);
}
int main() {
    int T;
    long long x, y;
    cin >> T;

    while (T--) {
        cin >> x >> y;
        cout << solution(x, y) << '\n';
    }
    return 0;
}