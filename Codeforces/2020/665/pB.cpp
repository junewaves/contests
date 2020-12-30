#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

void solve() {
    int a[3], b[3];
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    int c = min(a[2], b[1]);
    int ans = c * 2;
    a[2] -= c, b[1] -= c;
    b[2] -= min(b[2], a[0] + a[2]);
    a[1] -= min(a[1], b[0] + b[1]);
    ans -= min(a[1], b[2]) * 2;
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