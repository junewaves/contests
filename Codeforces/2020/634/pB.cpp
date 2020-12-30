#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string ans;
    for (int i = 0, j = 0; i < n; i++) {
        ans += char('a' + j);
        j = (j + 1) % b;
    }
    cout << ans << '\n';
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