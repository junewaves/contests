#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    for (int& va : a)
        cin >> va, va--;
    for (int& vb : b) {
        cin >> vb, vb--;
    }
    for (int i = 0; i < n; i++) {
        c[a[i]] = i;
        d[b[i]] = i;
    }
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        int diff = c[i] - d[i];
        if (diff < 0)
            diff += n;
        dp[diff]++;
    }
    int mx = 0;
    for (int i : dp)
        mx = max(mx, i);
    cout << mx << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
