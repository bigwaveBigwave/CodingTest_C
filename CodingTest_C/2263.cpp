#include <iostream>
#include <vector>
using namespace std;

class TreeRebuilder {
public:
    // 노드 값이 1 ~ N 이라고 가정(백준 2263 형태)
    TreeRebuilder(const vector<int>& inorder, const vector<int>& postorder)
        : inorder_(inorder),
        postorder_(postorder),
        indexInInorder_(inorder.size() + 1, -1) {

        const int n = static_cast<int>(inorder_.size());
        // 값 -> inorder 인덱스 매핑
        for (int i = 0; i < n; ++i) {
            indexInInorder_[inorder_[i]] = i;
        }
    }

    void printPreorder() {
        const int n = static_cast<int>(inorder_.size());
        buildAndPrint(0, n - 1, 0, n - 1);
    }

private:
    const vector<int>& inorder_;
    const vector<int>& postorder_;
    vector<int> indexInInorder_; // value -> inorder index

    void buildAndPrint(int inL, int inR, int postL, int postR) {
        if (inL > inR || postL > postR) return;

        int root = postorder_[postR];
        cout << root << ' ';

        int rootIdx = indexInInorder_[root];
        int leftSize = rootIdx - inL;

        // 왼쪽 서브트리
        buildAndPrint(inL, rootIdx - 1,
            postL, postL + leftSize - 1);

        // 오른쪽 서브트리
        buildAndPrint(rootIdx + 1, inR,
            postL + leftSize, postR - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; ++i) cin >> inorder[i];
    for (int i = 0; i < n; ++i) cin >> postorder[i];

    TreeRebuilder solver(inorder, postorder);
    solver.printPreorder();
    return 0;
}
