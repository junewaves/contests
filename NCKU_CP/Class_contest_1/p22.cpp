#include <bits/stdc++.h>
using namespace std;
// problem source: https://judge.csie.ncku.edu.tw/problems/22
constexpr int M = 1000000009;
int dp[1001][1001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, k;
    int ans = 0;
    cin >> N >> k;
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 0;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1]) % M;
        }
    }
    for (int j = 1; j <= k; j++)
        ans = (ans + dp[N][j]) % M;
    cout << ans << '\n';
    return 0;
}