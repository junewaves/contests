#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    default_random_engine eng(0);
    uniform_int_distribution<ll> dist(1, LLONG_MAX);
    /*
    for (ll& va : a)
        cin >> va;*/
    for (int i = 0; i < n; i++) {
        a[i] = dist(eng);
        // cout << a[i] << " ";
    }
    // cout << endl;
    sort(a.rbegin(), a.rend());
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                ll dp = a[i] | a[j] | a[k];
                mx = max(mx, dp);
            }
        }
    }
    cout << mx << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
