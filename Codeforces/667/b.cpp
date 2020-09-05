#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int64_t a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        // a - x, 
        if (a - x + b - y <= n) {
            cout << x * y << '\n';
        } else {
            int64_t ans = LLONG_MAX;
            // -a
            int64_t aa = max(a - n, x);
            int64_t bb = b - max(n - (a - x), 0LL);
            ans = min(ans, aa * bb);
            bb = max(b - n, y);
            aa = a - max(n - (b - y), 0LL);
            ans = min(ans, aa * bb);
            cout << ans << '\n';
        }
    }
    return 0;
}