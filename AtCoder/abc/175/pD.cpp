#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n), c(n);
    for (ll& it : p)
        cin >> it, --it;
    for (ll& it : c)
        cin >> it;
    vector<vector<ll>> pre(n, vector<ll>(1, 0));
    for (int i = 0; i < n; i++) {
        int idx = p[i];
        pre[i].push_back(c[i]);
        while (idx != i) {
            pre[i].push_back(pre[i].back() + c[idx]);
            idx = p[idx];
        }
    }
    ll ans = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        ll sum = 0, len = (ll)pre[i].size() - 1;
        if (pre[i].back() > 0) {
            ll l = k / len, r = k % len;
            sum += pre[i].back() * l;
            sum += *max_element(pre[i].begin() + (l == 0), pre[i].begin() + r + 1);
            if (l >= 1) {
                ll altsum = pre[i].back() * (l - 1);
                altsum += *max_element(pre[i].begin() + 1, pre[i].end());
                sum = max(sum, altsum);
            }
        } else {
            ll r = min(len, k);
            sum += *max_element(pre[i].begin() + 1, pre[i].begin() + r + 1);
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}