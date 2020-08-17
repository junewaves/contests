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
    ll x, d, k;
    cin >> x >> k >> d;
    ll y = abs(x);
    ll m = y / d;
    ll ans = 0;
    if (m > k) {
        ans = y - k * d;
    } else if (m == k) {
        ans = y - (m * d);
    } else {
        ll a = y - m * d;
        ll b = y - (m + 1) * d;
        ll n = k - m;
        ans = n % 2 ? b : a;
    }
    cout << abs(ans);
    return 0;
}