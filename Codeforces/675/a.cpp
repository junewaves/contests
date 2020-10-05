#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t a, b, c;
    cin >> a >> b >> c;
    cout << a + b + c - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}