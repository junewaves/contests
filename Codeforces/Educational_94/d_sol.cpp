#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& it : a) cin >> it, --it;
    vector<int> cntr(n), cntl(n);
    ll ans = 0;
    for (int i = 0; i < n - 2; i++) {
        fill(cntr.begin(), cntr.end(), 0);
        for (int j = n - 1; j > i; j--) {
            ans += (ll)cntl[a[j]] * (ll)cntr[a[i]]; 
            cntr[a[j]]++;
        }
        cntl[a[i]]++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}