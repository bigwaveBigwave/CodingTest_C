#include<vector>
#include<stack>
#include<queue>
using namespace std;

//문제해석
//1과 0으로 이루어진 이차원 배열에서 1인 위치만 지나면서 n,m에 도착하는 경우 중 거리가 가장 짧은 경우의 거리를 출력하기(갈 수 없으면 -1)

/*
방문배열선언
최솟값 변수 선언
스택 선언
방향인덱스 선언

1,1에서부터 스택에 집어넣고,
스택이 비지 않을 때까지
스택의 맨 위의 x, y 값을 pair에 넣고 스택에서 지우고
그 값의 방향인덱스를 왼오위아래 해서
범위가 0이하거나 인덱스를 넘어가면 다른 방향
인덱스 에 0이 있거나 이미 방문했으면 다른방향
해가지고 적절한 방향을 스택에 넣는다
*/
int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 0));
    int answer = 0;
    queue<pair<int, int>> s1;
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    //시작점이 벽이면 바로 -1
    if (maps[0][0] == 0) return -1;


    dist[0][0] = 1;
    s1.push({ 0,0 });
    while (!s1.empty()) {
        pair<int, int> p = s1.front(); s1.pop();

        if (p.first == n - 1 && p.second == m - 1) return dist[p.first][p.second];
        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maps[nx][ny] == 0 || dist[nx][ny] != 0) continue;

            dist[nx][ny] = dist[p.first][p.second] + 1;
            s1.push({ nx, ny });
        }

    }
    //큐가 비었는데 도달 못했으면 -1
    return -1;
}