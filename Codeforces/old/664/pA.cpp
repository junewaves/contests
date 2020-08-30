#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int mn = min({a, b, c});
    int odd = (a & 1) + (b & 1) + (c & 1) + (d & 1);
    cout << (odd <= 1 || (odd >= 3 && mn > 0) ? "Yes\n" : "No\n");
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