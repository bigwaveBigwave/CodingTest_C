#include <iostream>
#include <vector>
using namespace std;

class TreeRebuilder {
public:
    TreeRebuilder(int n, vector<int> inorder, vector<int> postorder)
        : n_(n), inorder_(move(inorder)), postorder_(move(postorder)), indexInInorder_(n_ + 1, -1) {
        // ∞™ -> inorder ¿Œµ¶Ω∫
        for (int i = 0; i < n_; ++i) {
            indexInInorder_[inorder_[i]] = i;
        }
    }

    void printPreorder(ostream& out) const {
        buildAndPrint(0, n_ - 1, 0, n_ - 1, out);
    }

private:
    int n_;
    vector<int> inorder_;
    vector<int> postorder_;
    vector<int> indexInInorder_; // value -> inorder index

    void buildAndPrint(int inL, int inR, int postL, int postR, ostream& out) const {
        if (inL > inR || postL > postR) return;

        const int root = postorder_[postR];
        out << root << ' ';

        const int rootIdx = indexInInorder_[root];
        const int leftSize = rootIdx - inL;

        // Left subtree
        buildAndPrint(inL, rootIdx - 1,
            postL, postL + leftSize - 1, out);

        // Right subtree
        buildAndPrint(rootIdx + 1, inR,
            postL + leftSize, postR - 1, out);
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

    TreeRebuilder solver(n, move(inorder), move(postorder));
    solver.printPreorder(cout);
    return 0;
}
