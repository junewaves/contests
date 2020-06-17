#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int n;
/* for binary search
bool chk(string& s, int m) {
    int check[3] = { 0, 0, 0 };
    bool ok = false;
    for (int i = 0; i < n; i++) {
        check[s[i] - '1']++;
        if (i >= m) {
            check[s[i - m] - '1']--;
        }
        if (check[0] && check[1] && check[2]) {
            ok = true;
            break;
        }
    }
    return ok;
}*/
void solve() {
    string s;
    cin >> s;
    n = s.size();
    if (n < 3) {
        cout << "0\n";
        return;
    }
    /* sol 1: binary search
    int l = 3, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (chk(s, m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (l == n && !chk(s, n))
        cout << 0 << '\n';
    else
        cout << l << '\n';*/
    // sol 2:
    vector<pair<char, int>> c;
    for (char x : s) {
        if (c.empty() || c.back().first != x)
            c.emplace_back(x, 1);
        else
            c.back().second++;
    }
    int m = (int)c.size() - 1, ans = 1e9;
    for (int i = 1; i < m; i++) {
        if (c[i - 1].first != c[i + 1].first)
            ans = min(ans, c[i].second + 2);
    }
    cout << (ans <= n ? ans : 0) << '\n';
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
