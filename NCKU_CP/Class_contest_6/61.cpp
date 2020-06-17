#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    // for (int i = b; i <= c; i++) {
    //     ll x = c - i + 1;
    //     ll y = d - i + 1;
    //     if (x > b || y < a)
    //         continue;
    //     ll w = min(b, max(a, x)) - x + 1;
    //     ll z = min(b, max(a, y)) - x + 1;
    //     ans += (w + z) * (z - w + 1) / 2;
    // }
    ll e = b - a + 1;
    ll f = c - a + 1;
    ll g = min(e, f);
    ll h = max(e, f);
    for (int i = c; i <= d; i++) {
        ll x = i - (a + b);
        if (x > g && x < h)
            ans += g * (g - 1) / 2 + g * (x - g + 1);
        else if (x >= h)
            ans += (x - h) * (x - h + 1) / 2;
        else
            ans +=
                g * (g - 1) / 2 + g * (h - g + 1) + (x - h) * (x - h + 1) / 2;
    }
    cout << ans << '\n';
    return 0;
}
