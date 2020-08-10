#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& it : a)
        cin >> it;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        ans += a[i][m - 1] != 'D';
    for (int j = 0; j < m - 1; j++)
        ans += a[n - 1][j] != 'R';
    cout << ans << '\n';
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