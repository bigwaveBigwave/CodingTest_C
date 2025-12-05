#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, w, L;//트럭의 수, 다리의 길이, 최대 하중
int timee = 0;//소요시간
int sum = 0;//소요시간
queue<int> bridge;//다리위 트럭의 위치
queue<int> wait;//다리 안 간 트럭들


int main() {
    cin >> n >> w >> L;

    for (int i = 0; i < n; i++) {
        int weight;//트럭의 무게
        cin >> weight;
        wait.push(weight);
    }
    for (int i = 0; i < w; i++) {
        bridge.push(0);
    }

    while (!bridge.empty()) {
        timee++;

        //1. 한 칸 전진 : 맨 앞 칸 트럭(또는 0)이 나감
        sum -= bridge.front();
        bridge.pop();

        //2. 새 트럭을 올릴 수 있는지 확인
        if (!wait.empty()) {
            if (sum + wait.front() <= L) {
                //올릴 수 있다면 트럭 진입
                int x = wait.front();
                wait.pop();
                bridge.push(x);
                sum += x;
            }
            else {
                //못 올리면 빈칸(0)만 올리기
                bridge.push(0);
            }
        }
    }

    cout << timee << "\n";

    return 0;
}