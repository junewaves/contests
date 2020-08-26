#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    int x;
    cin >> s >> x;
    string w(s.size(), '1');
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '0') {
            if (i - x >= 0)
                w[i - x] = '0';
            if (i + x < (int)s.size())
                w[i + x] = '0';
        }
    }
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '1') {
            bool cnt1 = false;
            if (i - x >= 0 && w[i - x] == '1')
                cnt1 = true;
            if (i + x < (int)s.size() && w[i + x] == '1')
                cnt1 = true;
            if (!cnt1) {
                cout << "-1\n";
                return;
            }
        }
    }
    cout << w << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}