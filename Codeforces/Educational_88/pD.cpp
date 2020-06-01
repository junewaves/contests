#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& it : a)
        cin >> it;
    int ans = 0;
    for (int mx = 1; mx <= 30; mx++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > mx) {
                sum = 0;
            } else {
                sum += a[i];
            }
            sum = max(sum, 0);
            ans = max(ans, sum - mx);
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
