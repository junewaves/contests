#include <bits/stdc++.h>
using namespace std;
#ifndef _LOCAL_DEBUG
#define endl '\n'
#endif
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> m(n, 0);
    vector<ll> pre(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
        pre[i] = (i == 0 ? 0 : pre[i - 1]) + m[i];
    }
    vector<ll> dp(n, 0);
    ll s = 0;
    for (int i = 0; i < k - 1; i++) {
        s += m[i];
        dp[i] = s;
    }
    s = dp[k > 1 ? k - 2 : 0];
    for (int i = k - 1; i < n; i++) {
        ll ps = 0, p = 0;
        for (int j = i; j > i - k + 1; j--) {
            ps += m[j];
            p = max(p, ps + (j > 1 ? dp[j - 2] : 0));
        }
        dp[i] = p;
        s = max(s, dp[i]);
    }
    cout << s << endl;
}