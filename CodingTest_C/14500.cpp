#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
//문제해석
/*
정사각형 네개가 이어져서 만들어진 테트로미노를 숫자판 위에 올려놓았을 때(회전, 대칭 가능),
그 4개의 숫자의 합의 최댓값을 구하라
*/

//수도코드 1
/*
종이의 크기 N, M 입력받기
종이 벡터 선언
방문 벡터 선언
가장 큰 값 주변의 가장 큰 수들로만 세 수를 탐색해서 그 합을 구하기. -- 1)
1 - 1) 가장 큰 수의 좌표값 저장하기
1 - 2) 가장 큰 수의 주변에서 BFS 세 번 돌리기
1 - 3) 각 최댓값의 위치에서 BFS를 돌리면 값이 계속 나올텐데 그 중 최댓값을 계속 갱신하기.
*/

//수도코드 2
/*
종이의 크기 N, M 입력받기
종이 벡터 선언

각 모양들을 백트래킹 -- 1)
1 - 1) 각 모양을 회전시킨 경우의 수도 포함해서 백트래킹
1 - 2) 가장 큰 수의 주변에서 BFS 세 번 돌리기
1 - 3) 각 최댓값의 위치에서 BFS를 돌리면 값이 계속 나올텐데 그 중 최댓값을 계속 갱신하기.
*/

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, -1, 0 };
int N, M;
int maxValue = 0;//숫자판의 최댓값
int answer = 0;//목표인 최댓값
int main() {
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M));
    //vector<vector<int>> visit(N, vector<int> (M, 0));
    //vector<pair<int, int>> maxValueSearch;
    //queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    return 0;
}