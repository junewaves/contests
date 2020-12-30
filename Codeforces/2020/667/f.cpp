#include <bits/stdc++.h>
using namespace std;

int n, k, dp[201][201][201];
string s, t;
int go(int pos, int nt, int cur) {
    if (pos >= n)
        return 0;
    if (dp[pos][nt][cur] != -1)
        return dp[pos][nt][cur];
    int ans = 0;
    // do nothing
    ans = max(ans, go(pos + 1, nt, cur));
    // chenge to t[0]
    int cost = int(s[pos] != t[0]);
    if (cur - cost >= 0)
        ans = max(ans, go(pos + 1, nt + 1, cur - cost));
    // chenge to t[1]
    cost = int(s[pos] != t[1]);
    if (cur - cost >= 0)
        ans = max(ans, nt + go(pos + 1, nt, cur - cost));
    return dp[pos][nt][cur] = ans;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cin >> n >> k >> s >> t;
    if (t[0] == t[1]) {
        int cnt = 0;
        for (char c : s) {
            if (c == t[0])
                cnt++;
        }
        cnt = min(n, cnt + k);
        cout << cnt * (cnt - 1) / 2 << '\n';
        return 0;
    }
    cout << go(0, 0, k) << '\n';
    return 0;
}