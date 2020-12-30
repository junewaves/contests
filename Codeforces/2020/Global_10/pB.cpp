#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    int mx = -2e9, mn = 2e9;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    bool flag = k % 2;
    for (int i = 0; i < n; i++) {
        if (a[i] == mx)
            cout << (flag ? 0 : mx - mn) << ' ';
        else if (a[i] == mn)
            cout << (flag ? mx - mn : 0) << ' ';
        else 
            cout << (flag ? mx - a[i] : a[i] - mn) << ' ';
    }
    cout << '\n';
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