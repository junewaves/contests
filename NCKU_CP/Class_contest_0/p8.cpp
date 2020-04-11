#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
// problem source: https://judge.csie.ncku.edu.tw/problems/8
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, L;
    cin >> n >> L;
    vector<int> a(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(L + 1, INT_MIN));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1][min(a[1], L)] = 0;
    for (int i = 2; i <= n; i++) {
        for (int P = 0; P <= L; P++) {
            int x = min(P, a[i]), y = min(P + a[i], L);
            dp[i][P - x] = max(dp[i - 1][P] + x, dp[i][P - x]);
            dp[i][y] = max(dp[i - 1][P], dp[i][y]);
        }
    }
    a[0] = -1;
    for (int P = 0; P <= L; P++) {
        if (dp[n][P] > a[0])
            a[0] = dp[n][P];
    }
    cout << a[0] << endl;
    return 0;
}