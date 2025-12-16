// you can use includes, for example:
#include <algorithm>
#include<climits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
/*
목표 : 배열 A에 의해 성취될 수 있는 최댓값 구하기
한 선수를 위한 게임은 0에서 N-1로 넘버링된 NxN 보드에서 열린다.
각 보드에는 숫자가 있다.
정수 N으로 이루어진 배열 A는 비지 않고 보드에 있는 숫자가 쓰여진다.
더불어 몇개의 각 보드 네모는 게임하는 동안 표시될 수 있다.

게임의 초반부에는 숫자 0이 있다
그리고 이것은 표시된 유일한 스퀘어다.
게임의 목적은 pebble을 N-1로 옮기는 것이다.

주사위를 던지는


NxN 보드가 있음
N 배열이 N개 있음
배열은 비지 않고 숫자가 써 있음
각 배열의 요소는 표시될 수도 있음
이 게임의 목적은  ???

주사위 한번~A배열크기-1번 던진 것의 각 최댓값 중에 최댓값 구하기
*/

//점화식 : n개의 요소값을 더했을 때의 값(최대여야함)

int solution(vector<int>& A) {
    // Implement your solution 
    int N = (int)A.size();
    vector<int> dp(N, INT_MIN);
    dp[0] = A[0];
    for (int i = 0; i < N; i++) {
        int best = INT_MIN;
        for (int k = 1; k <= 6; k++) {
            if (i - k > 0) {
                best = max(best, dp[i - k]);


            }


        }
        dp[i] = best + A[i];


    }

    return dp[N - 1];

}