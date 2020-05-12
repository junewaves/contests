#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int mxN = 1e5 + 1;
int n, a[mxN], pre[mxN], suf[mxN], b[mxN];
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 2) {
        cout << (ll)a[0] * a[1] / __gcd(a[0], a[1]) << endl;
        return;
    }
    pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre[i] = __gcd(pre[i - 1], a[i]);
    }
    /*
        for (int i = 0; i < n; i++) {
            cout << pre[i] << " ";
        }
        cout << endl;
    */
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = __gcd(suf[i + 1], a[i]);
    }
    /*
        for (int i = 0; i < n; i++) {
            cout << suf[i] << " ";
        }
        cout << endl;
    */
    for (int i = 0; i < n; i++) {
        if (i == 0)
            b[i] = suf[i + 1];
        else if (i == n - 1)
            b[i] = pre[i - 1];
        else {
            b[i] = __gcd(pre[i - 1], suf[i + 1]);
        }
        // cout << b[i] << " ";
    }
    // cout << endl;

    int mm = __gcd(a[0], suf[1]);
    ll ans = mm;
    for (int i = 0; i < n; i++) {
        ans *= (b[i] / mm);
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
