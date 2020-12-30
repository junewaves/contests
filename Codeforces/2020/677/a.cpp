#include <bits/stdc++.h>
using namespace std;

const int cnt[4] = {1, 3, 6, 10};
void solve() {
    string s;
    cin >> s;
    int x = s[0] - '0';
    int y = s.size();
    cout << 10 * (x - 1) + cnt[y - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}