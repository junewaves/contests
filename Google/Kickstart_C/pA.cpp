#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
typedef long long int ll;
const int mxN = 2e5 + 1;
int a[mxN];
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i <= n - k; i++) {
        if (a[i] == k) {
            bool ok = true;
            for (int j = i + 1, m = k - 1; j < n && m > 0; j++, m--) {
                if (a[j] != m) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                ans++;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    for (int i = 1; i <= _n; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
