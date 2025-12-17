//목표 : 수열과 연산자의 개수가 주어졌을 때, 수열의 연산 조합값 중 최대, 최소값을 구해라

/*
수도코딩 :
수열 크기만큼 벡터 선언
수열 집어넣기
연산자 수 입력받기
연산자랑 수열을 조합하기 --- 1)
1 - 1) 수열은 가만히. 연산자가 움직임. 모든 연산자의 조합이
하나하나 조합하면서 최댓값 최솟값 갱신하기
*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    vector<int> oper(4);
    for (int j = 0; i < 4; j++) {
        cin >> oper[j];
    }
    int maxV = 0;
    int minV = 0;


    return 0;
}