#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n;
    cin >> n;
    ll d = n;
    int cnt = 0;
    while (d) {
        if (d & 1)
            cnt++;
        d >>= 1;
    }
    cout << 2LL * n - cnt << '\n';
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
