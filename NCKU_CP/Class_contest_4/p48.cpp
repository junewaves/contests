#include <bits/stdc++.h>
#ifndef _LOCAL_DEBUG
#define endl '\n'
#endif
using namespace std;
typedef long long ll;
ll dp[101][101];
ll Get(int n, int m) {
    return dp[min(n, m)][max(n, m)];
}
void Set(int n, int m, int i) {
    dp[n][m] = dp[m][n] = i;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int k = max(n, m);
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            if (i == 1 || j == 1)
                Set(i, j, max(i, j));
            else if (i == j) {
                Set(i, j, 1);
            } else {
                Set(i, j, INT_MAX);
            }
        }
    }
    for (int i = 2; i <= k; i++) {
        for (int j = 2; j <= i; j++) {
            ll M = INT_MAX;
            for (int a = 1; a <= j; a++) {
                ll _k = Get(a, j) + Get(i - a, j);
                // cout << _k << " ";
                M = min(M, _k);
            }
            Set(i, j, M);
            // cout << endl;
        }
    }
    cout << Get(n, m) << endl;

    // // cout << recur(n, m) << '\n';
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
}
