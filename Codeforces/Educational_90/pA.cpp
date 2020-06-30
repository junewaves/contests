#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a >= c) {
        cout << "-1 " << b << "\n";
        return;
    }
    if (a * b > c) {
        cout << "1 " << b << "\n";
    } else if (a * b <= c) {
        cout << "1 -1\n";
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