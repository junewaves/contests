#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...)
#endif

int n, m, dp[1 << 9], a[200], b[200];
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<int> y;
        for (int j = 0; j < m; j++) {
            int c = a[i] & b[j];
            if (dp[c] & 1)
                dp[c] |= 2;
            else
                y.push_back(c);
        }
        for (int k = 0; k < (1 << 9); k++) {
            if (dp[k] & 1) {
                for (int c : y)
                    dp[k | c] |= 2;
            }
            dp[k] >>= 1;
        }
    }
    for (int i = 0; i < (1 << 9); i++) {
        if (dp[i]) {
            cout << i << '\n';
            return;
        }
    }
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