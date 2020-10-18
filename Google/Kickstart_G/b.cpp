#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> coin(2 * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = 0;
            cin >> x;
            coin[i - j + n] += x;
        }
    }
    cout << *max_element(coin.begin(), coin.end()) << '\n';
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