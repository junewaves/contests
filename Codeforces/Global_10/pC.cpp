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
    cin >> n;
    vector<int> a(n);
    for (int& it : a)
        cin >> it;
    ll ans = 0;
    for (int i = n - 1; i > 0; i--) {
        if (a[i] < a[i - 1])
            ans += a[i - 1] - a[i];
    }
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