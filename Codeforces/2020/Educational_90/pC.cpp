#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n + 1), dp(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '+')
            a[i] = a[i - 1] + 1;
        else
            a[i] = a[i - 1] - 1;
        if (a[i] < 0 && dp[-a[i]] == -1) {
            dp[-a[i]] = i;
        }
    }
    ll ans = n;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == -1)
            break;
        ans += dp[i];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}