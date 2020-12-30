#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t x, y, k;
    cin >> x >> y >> k;
    int64_t need = k * y + k;
    cout << (need - 1 + x - 1 - 1) / (x - 1) + k << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}