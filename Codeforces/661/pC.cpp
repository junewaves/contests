#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

int w[51];
void solve() {
    memset(w, 0, 4 * 51);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        w[t]++;
    }
    int ans = 0;
    for (int i = 2; i <= n * 2; i++) {
        int sum = 0;
        for (int a = 1; a <= i / 2; a++) {
            if (i - a > n || i - a < 1)
                continue;
            if (a == i - a) {
                sum += w[a] / 2;
            } else {
                sum += min(w[a], w[i - a]);
            }
        }
        ans = max(ans, sum);
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