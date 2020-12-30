#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll max_sum(const vector<int>& d) {
    ll mx = 0, sum = 0;
    for (int x : d) {
        sum += x;
        sum = max(sum, 0LL);
        mx = max(mx, sum);
    }
    return mx;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll even = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2 == 0)
            even += a[i];
    }
    vector<int> dp(n / 2);
    for (int i = 0; i + 1 < n; i += 2)
        dp[i / 2] = a[i + 1] - a[i];
    ll x1 = max_sum(dp);
    fill(dp.begin(), dp.end(), 0);
    for (int i = 1; i + 1 < n; i += 2)
        dp[i / 2] = a[i] - a[i + 1];
    ll x2 = max_sum(dp);
    cout << even + max({ 0LL, x1, x2 }) << '\n';
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