#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n;
void solve() {
    cin >> n;
    // min of additional bullets needed to initate explosion from some monster
    ll min_to_init = LONG_LONG_MAX;
    // sum for every monster
    // the bullets needed to kill it after taking explosion damage
    ll cnt = 0;
    // only need to storage 3 monster's info at a time at most:
    // only storing monster: m[0] = m(0), m[1] = m(i-1), m[2] = m(i)
    ll m[4][2];
    cin >> m[0][0] >> m[0][1];  // store monster 0's info
    m[1][0] = m[0][0];
    m[1][1] = m[0][1];
    for (int i = 1; i < n; i++) {
        cin >> m[2][0] >> m[2][1];
        if (i > 0) {
            cnt += max(0LL, m[2][0] - m[1][1]);
            min_to_init = min({ min_to_init, m[2][0], m[1][1] });
        }
        m[1][0] = m[2][0];
        m[1][1] = m[2][1];
    }
    // calculate final monster (m[0])
    cnt += max(0LL, m[0][0] - m[1][1]);
    min_to_init = min({ min_to_init, m[0][0], m[1][1] });
    cout << cnt + min_to_init << endl;
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