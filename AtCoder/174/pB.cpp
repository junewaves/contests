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
    ll n, d;
    cin >> n >> d;
    d = d * d;
    int ans = 0;
    for (int i = 0; i < n ; i++) {
        ll x, y;
        cin >> x >> y;
        if (x * x + y * y <= d)
            ans++;
    }
    cout << ans << '\n';
    return 0;
}