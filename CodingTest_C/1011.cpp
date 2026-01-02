#include<iostream>
#include<cmath>
using namespace std;


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