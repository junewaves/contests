#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...)
#endif

int r, c, n;
vector<vector<ll>> a;
vector<vector<array<ll, 4>>> dp;

void maxi(ll& x, ll y) {
    x = max(x, y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> r >> c >> n;
    a.resize(r, vector<ll>(c));
    dp.resize(2, vector<array<ll, 4>>(c));
    for (int x = 0; x < n; x++) {
        int i, j, v;
        cin >> i >> j >> v;
        a[i - 1][j - 1] = v;
    }
    dp[0][0][1] = a[0][0];
    for (int i = 0; i < r; i++) {
        dp[1].assign(c, {0, 0, 0, 0});
        for (int j = 0; j < c; j++) {
            for (int k = 0; k <= 3; k++) {
                if (i + 1 < r) {
                    maxi(dp[1][j][0], dp[0][j][k]);
                    if (a[i + 1][j] != 0)
                        maxi(dp[1][j][1], dp[0][j][k] + a[i + 1][j]);
                }
                if (j + 1 < c) {
                    maxi(dp[0][j + 1][k], dp[0][j][k]);
                    if (k < 3 && a[i][j + 1] != 0)
                        maxi(dp[0][j + 1][k + 1], dp[0][j][k] + a[i][j + 1]);
                }
            }
        }
        if (i + 1 < r)
            copy(dp[1].begin(), dp[1].end(), dp[0].begin());
    }
    cout << *max_element(dp[0][c - 1].begin(), dp[0][c - 1].end());
    return 0;
}