#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    string s, ans;
    cin >> s;
    ans.push_back(s[0]);
    int n = s.size();
    for (int i = 1; i < n; i += 2)
        ans.push_back(s[i]);
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
