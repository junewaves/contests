#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segTree {
    int N;
    vector<ll> val;
    segTree(int _n) : N(_n) {
        // initialize array as 0
        val.resize(2 * N);
    }
    void update(int i, int d) {
        for (val[i += N] += d; i >>= 1;) {
            val[i] = val[i << 1] + val[i << 1 | 1];
        }
    }
    ll query(int l, int r) {
        ll res = 0;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1)
                res += val[l++];
            if (r & 1)
                res += val[--r];
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> op(n);
    vector<vector<int>> cl(n);
    for (int& it : a) cin >> it;
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j++) {
            if (a[i] == a[j]) {
                op[i]++;
                cl[j].push_back(i);
            }
        }
    }
    segTree t(n);
    ll ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (cl[i].size()) {
            reverse(cl[i].begin(), cl[i].end());
            for (int j : cl[i]) {
                int q = t.query(j + 1, i);
                ans += q;
                t.update(j, -1);
            }
        }
        if (op[i] > 0) {
            t.update(i, op[i]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}