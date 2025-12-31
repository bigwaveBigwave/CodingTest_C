#include<iostream>
#include<algorithm>
using namespace std;

int result(int x, int y, int w, int h) {
    //w가 가로 길이, h가 세로 길이인 직사각형.
    return min({ x, y, h - y, w - x });

}
int main() {

    int x, y, w, h;
    cin >> x >> y >> w >> h;
    cout << result(x, y, w, h);
    return 0;
}