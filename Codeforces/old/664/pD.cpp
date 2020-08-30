#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

void solve() {
    int n, d, m;
    cin >> n >> d >> m;
    vector<int> a[2];
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[t <= m].push_back(t);
    }
    sort(a[0].rbegin(), a[0].rend());
    sort(a[1].rbegin(), a[1].rend());
    ll ans, sum = 0;
    int i, j, c0 = a[0].size(), c1 = a[1].size(); 
    for (i = 0; i < c0 && (d + 1) * i < n; i++)
        sum += a[0][i];
    int lim = n - (d + 1) * (i - 1) - 1;
    for (j = 0; j < c1 && j < lim; j++) 
        sum += a[1][j];
    ans = sum;
    while (i > 0 || j < c1) {
        sum -= a[0][--i];
        for (int l = 0; j < c1 && l < d + 1; j++, l++)
            sum += a[1][j];
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}