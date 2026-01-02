#include<iostream>
using namespace std;
int answer = 0;//이동 횟수의 최솟값
int loc = 0;//현재 위치
int dist = 0;//이동 거리

int solution(int x, int y) {

    if (y - x == 1) {
        answer += 1;
        return answer;
    }
    else {

    }
}
int main() {
    int T, x, y;
    cin >> T;

    while (T--) {
        cin >> x >> y;
        solution(x, y);
    }
    return 0;
}