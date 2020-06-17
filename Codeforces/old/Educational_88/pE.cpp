#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int mxN = 5e5 + 1;
constexpr int MOD = 998244353;
ll F[mxN];

ll power(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y % 2)
            res = (x * res) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}

ll C(ll n, ll k) {
    if (k > n)
        return 0;
    // C(n, k) = n!/(k!(n-k)!)
    ll den = (F[k] * F[n - k]) % MOD;
    return (F[n] * power(den, MOD - 2)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    F[0] = 1;
    for (int i = 1; i < mxN; i++)
        F[i] = (F[i - 1] * i) % MOD;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int d = n / i;
        ans = (ans + C(d - 1, k - 1)) % MOD;
    }
    cout << ans << '\n';
}
