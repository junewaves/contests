#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& it : a)
        cin >> it;
    int ans = 0, mx = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        sum += a[i];
        ans = max(ans, sum - mx);
        if (sum < 0) {
            sum = 0;
            mx = max(0, a[i]);
        }
    }
    sum = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        sum += a[i];
        ans = max(ans, sum - mx);
        if (sum - mx < 0) {
            sum = 0;
            mx = max(0, a[i]);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
