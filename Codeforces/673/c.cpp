#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> ind(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        ind[a[i]].push_back(i);
    }
    vector<int> ans(n + 2, n + n);
    for (int i = 0; i < n; i++) {
        int start = -1;
        int mx = 0;
        for (int j : ind[i]) {
            mx = max(mx, j - start);
            start = j;
        }
        mx = max(mx, n - start);
        ans[mx] = min(ans[mx], i);
    }
    int mn = n + n;
    for (int i = 1; i <= n; i++) {
        mn = min(mn, ans[i]);
        if (mn > n)
            cout << -1 << ' ';
        else
            cout << mn + 1 << ' ';
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