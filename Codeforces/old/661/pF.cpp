#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...)
#endif

#define L first
#define R second
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i].L >> v[i].R;
        s.push_back(v[i].L);
        s.push_back(v[i].R);
    }
    sort(v.begin(), v.end());
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    int sz = s.size();
    vector<vector<int>> dp(sz, vector<int>(sz, -1)), seg(sz);
    for (int i = 0; i < n; i++) {
        v[i].L = lower_bound(s.begin(), s.end(), v[i].L) - s.begin();
        v[i].R = lower_bound(s.begin(), s.end(), v[i].R) - s.begin();
        seg[v[i].L].push_back(v[i].R);
    }
    function<int(int, int)> f = [&](int l, int r) -> int {
        if (l > r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];
        int full = count(seg[l].begin(), seg[l].end(), r);
        dp[l][r] = full + f(l + 1, r);
        for (int nr : seg[l]) {
            if (nr >= r)
                break;
            dp[l][r] = max(dp[l][r], full + f(l, nr) + f(nr + 1, r));
        }
        return dp[l][r];
    };
    cout << f(0, sz - 1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}