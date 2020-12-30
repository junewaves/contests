#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
void solve() {
    ll n, m;
    cin >> n >> m;
    if (n == 1)
        cout << 0 << endl;
    else if (n == 2)
        cout << m << endl;
    else
        cout << 2 * m << endl;
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
