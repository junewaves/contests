#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> s(26, 0);
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        s[c - 'a']++;
    }
    for (int len = n; len > 0; len--) {
        vector<bool> used(len);
        vector<int> cycle;
        for (int i = 0; i < len; i++) {
            if (used[i])
                continue;
            used[i] = true;
            cycle.push_back(0);
            cycle.back()++;
            int j = (i + k) % len;
            while (!used[j]) {
                cycle.back()++;
                used[j] = true;
                j = (j + k) % len;
            }
        }
        sort(cycle.begin(), cycle.end());
        priority_queue<int> cur(s.begin(), s.end());
        bool ok = true;
        while (!cycle.empty()) {
            if (cur.top() < cycle.back()) {
                ok = false;
                break;
            } else {
                int x = cur.top();
                cur.pop();
                cur.push(x - cycle.back());
                cycle.pop_back();
            }
        }
        if (ok) {
            cout << len << '\n';
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
    return 0;
}
