#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> a(n, string(n, '0'));
    for (int c = 0, i = 0, j = 0; c < k; c++, i++) {
        if (i == n)
            i = 0, j++;
        a[i][j] = '1';
        j = (j + 1) % n;
    }
    cout << (k % n == 0 ? 0 : 2) << '\n';
    for (auto x : a) {
        cout << x << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}