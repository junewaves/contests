#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            for (int j = 1; i - j >= 0 && j <= k; j++)
                s[i - j] = '2';
            for (int j = 1; i + j < n && j <= k; j++)
                s[i + j] = '2';
        }
    }
    // cout << s << '\n';
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            ++ans;
            for (int j = 1; i + j < n && j <= k; j++)
                s[i + j] = '2';
        }
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
