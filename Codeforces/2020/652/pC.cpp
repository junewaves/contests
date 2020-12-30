#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), w(k);
    for (int& it : a)
        cin >> it;
    for (int& it : w)
        cin >> it;
    sort(a.rbegin(), a.rend());
    sort(w.begin(), w.end());
    int j = 0;
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        if (w[i] == 1)
            ans += a[j] * 2;
        else
            ans += a[j];
        j++;
        w[i]--;
    }
    for (int i = 0; i < k; i++) {
        if (w[i] == 1) {
            ans += a[j];
            j++;
            w[i]--;
        } else if (w[i] > 1) {
            break;
        }
    }
    for (int i = 0; i < k; i++) {
        if (w[i]) {
            j += w[i];
            ans += a[j - 1];
        }
    }
    cout << ans << '\n';
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