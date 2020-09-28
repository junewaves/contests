#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    map<int, int> cnt;
    for (int& it : a)
        cin >> it, cnt[it]++;
    map<int, int> color;
    for (auto p : cnt) {
        if (color.find(p.first) == color.end()) {
            color[p.first] = 0;
            int bad = t - p.first;
            if (bad == p.first) {
                color[p.first] = -cnt[p.first] - 1;
            } else if (cnt.find(bad) != cnt.end()) {
                color[bad] = 1;
            }
        }
    }
    for (int i : a) {
        if (color[i] >= 0)
            cout << color[i] << ' ';
        else {
            cout << -color[i] % 2 << ' ';
            color[i]++;
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}