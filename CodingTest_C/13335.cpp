#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dd(vector<int> v) {
    int weight = 0;
    for (int i = 0; i < n; i++) {
        weight = v[i];
        if (weight < l) {
            dd(v);
        }
        else if (weight = l) {
            time += w;
            continue;
        }
    }
    int main() {
        int n, w, l;
        int time = 0;
        cin >> n >> w >> l;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        dd(v);

        cout << time;
    }
    return 0;
}