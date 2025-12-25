#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> inOrder;
vector<int> postOrder;
vector<int> pos;  // 값 -> 중위순회에서의 인덱스

void solve(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return;

    int root = postOrder[postEnd];       // 후위 순회의 마지막 = 루트
    cout << root << ' ';

    int rootIdx = pos[root];             // 중위 순회에서 루트의 위치
    int leftSize = rootIdx - inStart;    // 왼쪽 서브트리 크기

    // 왼쪽 서브트리
    solve(inStart, rootIdx - 1,
        postStart, postStart + leftSize - 1);

    // 오른쪽 서브트리
    solve(rootIdx + 1, inEnd,
        postStart + leftSize, postEnd - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    inOrder.resize(n);
    postOrder.resize(n);
    pos.resize(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> inOrder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> postOrder[i];
    }

    // 값 -> 인덱스 매핑 (중위순회에서의 위치)
    for (int i = 0; i < n; i++) {
        pos[inOrder[i]] = i;
    }

    solve(0, n - 1, 0, n - 1);
    return 0;
}
