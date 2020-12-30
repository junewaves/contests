#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int64_t> pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    unordered_set<int64_t> res;
    queue<pair<int, int>> que;
    que.emplace(1, n);
    while (que.size()) {
        auto [l, r] = que.front();
        que.pop();
        res.insert(pre[r] - pre[l - 1]);
        if (a[l] != a[r]) {
            int mid = (a[l] + a[r]) / 2;
            int it = upper_bound(a.begin() + l, a.begin() + r + 1, mid) - a.begin();
            que.emplace(l, it - 1);
            que.emplace(it, r);
        }
    }
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << (res.count(x) ? "Yes" : "No") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}