#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...)
#endif

void solve() {
    ll n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sum += x;
    }
    ll low = 0, high = 1e12 + 5, answer = -1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if ((2LL * mid + n - 1) * n / 2 <= sum) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    ll missing = sum - (2LL * answer + n - 1) * n / 2;
    for (int i = 0; i < n; i++) {
        cout << answer + i + (i < missing) << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}