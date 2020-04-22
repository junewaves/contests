#include <bits/stdc++.h>
using namespace std;
#ifndef _LOCAL_DEBUG
#define endl '\n'
#endif
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    vector<string> str(2);
    cin >> n >> str[0] >> str[1];
    vector<ll> res;
    for (string& s : str) {
        vector<vector<ll>> dp(3, vector<ll>(n, 0));
        // A
        dp[0][0] = s[0] == 'A' ? 1 : 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == 'A') {
                dp[0][i] = dp[0][i - 1] + 1;
            } else {
                dp[0][i] = dp[0][i - 1];
            }
        }
        // K
        dp[1][0] = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == 'K' && dp[0][i] > 0) {
                dp[1][i] = dp[1][i - 1] + dp[0][i];
            } else {
                dp[1][i] = dp[1][i - 1];
            }
        }
        // A
        dp[2][0] = dp[2][1] = 0;
        for (int i = 2; i < n; i++) {
            if (s[i] == 'A' && dp[1][i] > 0) {
                dp[2][i] = dp[2][i - 1] + dp[1][i];
            } else {
                dp[2][i] = dp[2][i - 1];
            }
        }
        res.push_back(dp[2][n - 1]);
    }
    if (res[0] == res[1])
        cout << "WINWIN\n";
    else if (res[0] > res[1])
        cout << "LanA WIN\n";
    else
        cout << "LanE WIN\n";
}