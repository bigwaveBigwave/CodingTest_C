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

int N;
vector<int> A;
int op[4]; //연산자
long long mx = LLONG_MIN;
long long mn = LLONG_MAX;

void dfs(int idx, long long curr) {
    if (idx == N) {
        mx = max(mx, curr);
        mn = min(mn, curr);
        return;
    }

    if (op[0] > 0) {
        op[0]--;
        dfs(idx + 1, curr + A[idx]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    for (int j = 0; j < 4; j++) {
        cin >> op[j];
    }
    
    dfs(1, A[0]);

    cout << mx << "\n" << mn << "\n";
    return 0;
}