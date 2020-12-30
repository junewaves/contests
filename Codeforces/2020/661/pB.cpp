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
    vector<int> a(n), b(n);
    for (int& it : a)
        cin >> it;
    for (int& it : b)
        cin >> it;
    int min_a = *min_element(a.begin(), a.end());
    int min_b = *min_element(b.begin(), b.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(a[i] - min_a, b[i] - min_b);
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