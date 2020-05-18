#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
typedef long long ll;
const int MAXN = 2e5 + 5;
int n, q, l, r, s, d;
struct BIT {
    ll node[MAXN];
    void update(int i, ll v) {
        for (; i <= n; i += (i & -i)) {
            node[i] += v;
        }
    }
    ll get(int i) {
        ll res = 0;
        for (; i > 0; i -= (i & -i)) {
            res += node[i];
        }
        return res;
    }
    ll query(int L, int R) { return get(R) - get(L); }
} score, sum;
void solve() {
    memset(score.node, 0, 8 * MAXN);
    memset(sum.node, 0, 8 * MAXN);
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s = i & 1 ? 1 : -1;
        score.update(i, (ll)s * i * a[i]);
        sum.update(i, s * a[i]);
    }
    char c;
    ll ans = 0;
    while (q--) {
        cin >> c >> l >> r;
        s = l & 1 ? 1 : -1;
        if (c == 'Q') {
            ans += s * (score.query(l - 1, r) - (l - 1) * sum.query(l - 1, r));
        } else {
            d = r - a[l];
            score.update(l, (ll)s * l * d);
            sum.update(l, s * d);
            a[l] = r;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    for (int i = 1; i <= _n; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
