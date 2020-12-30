#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
void solve() {
    ll n, sum = 0;
    cin >> n;
    for (ll i = 1, j = 1; i < n; i += 2, j++) {
        sum += 8LL * j * j;
    }
    cout << sum << endl;
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
