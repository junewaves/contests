#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

constexpr int mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll ans = 2, comb = 6;
    for (int i = 4; i <= n; i++) {
        ll pre = (comb - ans + mod) % mod;
        ans = (ans * i + pre * (i - 2)) % mod;
        comb = comb * i % mod;
    }
    cout << ans << '\n';
    return 0;
}