#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll& va : a)
        cin >> va;
    if (n == 1) {
        cout << a[0] << '\n';
        return;
    } else if (n == 2) {
        cout << (a[0] | a[1]) << '\n';
        return;
    }
    ll mx = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                mx = max(mx, a[i] | a[j] | a[k]);
    cout << mx << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
