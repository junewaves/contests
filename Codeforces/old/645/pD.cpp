#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> a(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    vector<ll> b = { 0 }, c = { 0 };
    for (int i = 0; i < 2 * n; i++) {
        b.push_back(b.back() + a[i]);
        c.push_back(c.back() + a[i] * (a[i] + 1) / 2);
    }
    ll ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (b[i + 1] >= x) {
            ll z = upper_bound(b.begin(), b.end(), b[i + 1] - x) - b.begin();
            ll cnt = c[i + 1] - c[z];
            ll days = b[i + 1] - b[z];
            ll ex = a[z - 1] - x + days;
            cnt += (a[z - 1] - ex) * (a[z - 1] + ex + 1) / 2;
            ans = max(ans, cnt);
        }
    }
    cout << ans << '\n';
    return 0;
}
