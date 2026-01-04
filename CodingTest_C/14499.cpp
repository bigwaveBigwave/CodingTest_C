#include<iostream>
#include<vector>
using namespace std;
//문제 해석 : 주사위의 위치 좌표와 이동 명령을 보고 주사위 이동마다 주사위 상단의 값을 도출하기.
//지도의 바깥으로 주사위를 이동시켜야할 때는 무시하기

//수도코딩
/*
지도 행렬, 주사위 현재 위치 좌표, 명령 개수 선언, 입력받기
주사위 상단 변수 선언(초기값 6)
주사위 하단 변수 선언(초기값 1)
위치 배열 선언
x[4] = 0,0,-1,1
y[4] = 1,-1,0,0
지도 좌표값 입력받기
while(명령개수--) {
명령 변수 선언, 입력받기
명령변수 입력받을때마다{
해당 방향으로 주사위의 위치 좌표 이동. 위치 배열 이용 -> 근데 지도 좌표값의 범위를 조건으로달고 범위 안 넘을때만 이동
주사위 위의 값 출력(방향의 반대에 있는 수가 위로 가게 됨) -> 명령 값이 1이면 상단값 4, 바닥값은 3

좌표값이 0이면 주사위의 바닥면의 숫자가 좌표값으로 이동
좌표값이 0이 아니면(=주사위 값만 존재) 칸의 수가 주사위 바닥으로 이동
}


}
*/

/*<구조화>
1. 계속 변화되는 상태
1 ) 주사위 6면 값 = 위 아래 북 남 서 동
2 ) 현재 위치
3 ) 지도 값

2. 한 턴 로직
1) 다음칸 계산
2) 범위 체크
3) 이동확정, 주사위 회전
4) 지도칸과 주사위 바닥면 교환
5) 주사위의 위 값 출력

3. 핵심 : 주사위 회전 규칙을 구조화
d[0] = top
d[1] = bottom
d[2] = north
d[3] = south
d[4] = west
d[5] = east

명령별 회전은 면의 자리바꿈
동
top <- west
bottom <- east
west <- bottom
east <- top

서
top <- ease
bottom <- west
west <- top
east <- bottom

북
남


*/

int main() {
    int N, M, x, y, count;
    cin >> N >> M >> x >> y >> count;
    vector<vector<int>> v(N, vector<int>(M));


    //지도 좌표 값 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }

    while (count--) {
        int instruction;
        cin >> instruction;
        x = x + dx[instruction];
        y = y + dy[instruction];
        if (x < 0 || y < 0 || x >= N || y >= M) {
            continue;
        }
        
            if (v[x][y] == 0) {
                v[x][y] = down;
            }
            else {
                down = v[x][y];
                cube[1][1] = down;
            }

    }
    return 0;
}