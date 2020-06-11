#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;
ll power(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1)
            res = x * res % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    map<int, int> p;
    for (int i = 0, tmp; i < n; i++) {
        scanf("%d", &tmp);
        p[tmp]++;
    }
    long long x, y, fp, ans = 1, d = 1;
    for (const auto& pr : p) {
        x = pr.first;
        y = pr.second;
        fp = power(x, y * (y + 1) / 2);
        ans = power(ans, y + 1) * power(fp, d) % MOD;
        d = d * (y + 1) % (MOD - 1);
    }
    printf("%lld\n", ans);
}