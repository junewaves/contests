#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int64_t ans = 0, pre = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'K') {
            if (s.substr(i, 4) == "KICK") {
                pre++;
            }
        } else if (s[i] == 'S') {
            if (s.substr(i, 5) == "START") { 
                ans += pre;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    for (int cn = 1; cn <= tt; cn++) {
        cout << "Case #" << cn << ": ";
        solve();
    }
    return 0;
}