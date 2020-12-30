#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    ll suma = 0, sumb = 0;
    for (int& it : a)
        cin >> it, suma += it;
    for (int& it : b)
        cin >> it, sumb += it;
    if (suma > sumb) {
        cout << "NO\n";
        return;
    }
    bool ok = true;
    ll s = 0, mx = -1e18;
    for (int i = 0; i < 2 * n; i++) {
        s += b[i % n] - a[i % n];
        mx = max(mx, s - b[i % n]);
        // cout << s << " " << mx << endl;
        if (s < mx)
            ok = false;
    }
    cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}