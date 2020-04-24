#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll pairSum(pair<int, ll>& p) {
    return (ll)p.first + p.second;
}
int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        scanf("%d", &n);
        puts("0");
        return 0;
    }
    if (n == 2) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", a + b);
        return 0;
    }
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &s[i]);
    }
    vector<vector<pair<int, ll>>> dp;  // value, steps
    dp.emplace_back(vector<pair<int, ll>>());
    for (int i = 0; i < n; i++) {
        dp[0].emplace_back(s[i], 0);
    }
    dp.emplace_back(vector<pair<int, ll>>());
    for (int i = 0; i + 1 < n; i++) {
        ll t = s[i] + s[i + 1];
        dp[1].emplace_back(t, t);
    }
    int x = 2;
    while (1) {
        dp.emplace_back(vector<pair<int, ll>>());
        for (int y = 0; y < n - x; y++) {
            ll best = LONG_LONG_MAX;
            for (int i = 0; i < x; i++) {
                int j = x - i - 1, b = i + y + 1;
                best = min(best, pairSum(dp[i][y]) + pairSum(dp[j][b]));
            }
            dp[x].emplace_back(dp[0][y].first + dp[x - 1][y + 1].first, best);
        }
        if (dp[x].size() == 1)
            break;
        x++;
    }
    printf("%lld\n", dp[x][0].second);
}