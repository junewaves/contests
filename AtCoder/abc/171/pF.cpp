#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int mxn = 2e6 + 1;
ll fac[mxn], inv[mxn];
ll power(ll x, ll y) {
    ll r = 1;
    while (y) {
        if (y & 1)
            r = (r * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return r;
}
ll C(int n, int r) {
    if (r < 0 || r > n)
        return 0;
    return ((fac[n] * inv[r]) % mod * inv[n - r]) % mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fac[0] = 1;
    for (int i = 1; i < mxn; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[mxn - 1] = power(fac[mxn - 1], mod - 2);
    for (int i = mxn - 1; i > 0; i--) {
        inv[i - 1] = inv[i] * (i) % mod;
    }
    int n, k;
    string s;
    cin >> k >> s;
    n = s.size();
    ll ans = 0;
    for (int i = n; i <= k + n; i++) {
        ans = (ans + C(k + n, i) * power(25, k + n - i)) % mod;
    }
    cout << ans << endl;
    return 0;
}