#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int mxN = 1e5;
int n, a[mxN];
void solve() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += abs(a[i]);
    }
    // unordered_map<int, int> dp;
    vector<int> dp(2 * sum + 1);
    dp[sum] = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        for (int j = 0; sum - j * j >= 0; j++) {
            ans += dp[sum - j * j];
        }
        dp[sum]++;
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
