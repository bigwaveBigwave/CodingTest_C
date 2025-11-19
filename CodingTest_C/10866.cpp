#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    deque<int> d;
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s == "push_back") {
            int val;
            cin >> val;
            d.push_back(val);
        }
        else if (s == "push_front") {
            int val;
            cin >> val;
            d.push_front(val);

        }
        else if (s == "pop_front") {
            if (d.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << d.front() << '\n';
                d.pop_front();
            }
        }
        else if (s == "pop_back") {
            if (d.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << d.back() << '\n';
                d.pop_back();
            }

        }
        else if (s == "size") {
            cout << d.size() << '\n';
        }
        else if (s == "empty") {
            cout << d.empty() << '\n';
        }
        else if (s == "front") {
            if (d.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << d.front() << '\n';
            }
        }
        else {
            if (d.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << d.back() << '\n';
            }
        }
    }
    return 0;
}