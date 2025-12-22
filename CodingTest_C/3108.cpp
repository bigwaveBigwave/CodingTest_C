#include <bits/stdc++.h>
using namespace std;

struct Rect {
    int x1, y1, x2, y2; // (left, bottom), (right, top)
};

// 두 직사각형이 테두리가 겹치거나 닿는지 확인
bool isOverlap(const Rect& a, const Rect& b) {
    // 한쪽이 다른 쪽을 완전히 포함 (테두리 안 닿음)
    if (a.x1 < b.x1 && a.y1 < b.y1 &&
        b.x2 < a.x2 && b.y2 < a.y2)
        return false;
    if (b.x1 < a.x1 && b.y1 < a.y1 &&
        a.x2 < b.x2 && a.y2 < b.y2)
        return false;

    // 완전히 떨어져 있는 경우
    if (a.x2 < b.x1 || b.x2 < a.x1 ||
        a.y2 < b.y1 || b.y2 < a.y1)
        return false;

    // 나머지는 전부 겹치거나 닿는 경우
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Rect> rects;
    rects.reserve(N + 1);

    // 0번: (0,0) ~ (0,0)인 "점 직사각형"
    rects.push_back({ 0, 0, 0, 0 });

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int lx = min(x1, x2);
        int rx = max(x1, x2);
        int by = min(y1, y2);
        int ty = max(y1, y2);
        rects.push_back({ lx, by, rx, ty });
    }

    int total = N + 1;
    vector<bool> visited(total, false);
    int components = 0;

    for (int i = 0; i < total; i++) {
        if (visited[i]) continue;
        components++;

        // BFS/DFS로 i와 연결된 애들 전부 방문
        queue<int> q;
        q.push(i);
        visited[i] = true;

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int j = 0; j < total; j++) {
                if (visited[j]) continue;
                if (!isOverlap(rects[cur], rects[j])) continue;
                visited[j] = true;
                q.push(j);
            }
        }
    }

    // (0,0)을 포함한 컴포넌트는 시작점이라 펜 안 내려도 되므로 -1
    cout << components - 1 << "\n";
    return 0;
}