#include <bits/stdc++.h>
using namespace std;
#ifndef _LOCAL_DEBUG
#define endl '\n'
#endif
typedef long long ll;
int dp[100][100][100];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    dp[0][0][0] = 1;
    dp[0][0][1] = 0;
    dp[0][1][0] = 0;
    dp[0][1][1] = 0;
    for (int x = 0; x < 100; x++) {
        if (x != 73) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (x >= 2)
                        dp[x][i][j] += dp[x - 2][i][j];
                    if (x >= 1 && i >= 1)
                        dp[x][i][j] += dp[x - 1][i - 1][j];
                    if (i >= 1)
                        dp[x][i][j] += dp[x][i - 1][j];
                    if (j >= 1)
                        dp[x][i][j] += dp[x][i][j - 1];
                    dp[x][i][j] = dp[x][i][j] % 48763;
                }
            }
        }
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cout << dp[97][i][j] << " ";
            s += dp[99][i][j];
        }
    }
    cout << s % 48763 << endl;
    return 0;
}