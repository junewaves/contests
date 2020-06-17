#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int mxN = 1e5 + 2;
int n, a[mxN], dp[mxN];
void solve() {
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > a[1])
            dp[i] = 2;
        else
            dp[i] = 1;
    }
    int mx = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j * i <= n; j++) {
            int k = j * i;
            if (a[k] > a[i]) {
                dp[k] = max(dp[k], dp[i] + 1);
            }
        }
        mx = max(mx, dp[i]);
    }
    cout << mx << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
    return 0;
}
