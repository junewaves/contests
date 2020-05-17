#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
typedef long long ll;
const int MAXN = 2e5 + 5;
int n, q;
struct BIT {
    int node[MAXN];
    void update(int i, int d) {
        for (; i <= n; i += (i & -i)) {
            node[i] += d;
        }
    }
    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= (i & -i)) {
            res += node[i];
        }
        return res;
    }
    int query(int l, int r) { return sum(r) - sum(l); }
} score, odd, even;
void solve() {
    memset(score.node, 0, 4 * MAXN);
    memset(odd.node, 0, 4 * MAXN);
    memset(even.node, 0, 4 * MAXN);
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i % 2) {
            score.update(i, i * a[i]);
            odd.update(i / 2 + 1, a[i]);
        } else {
            score.update(i, -i * a[i]);
            even.update(i / 2, a[i]);
        }
    }
    char c;
    int l, r, o1, o2, e1, e2, m, ans = 0;
    while (q--) {
        cin >> c >> l >> r;
        if (c == 'Q') {
            if (l % 2)
                o1 = l, e1 = l + 1, m = 1;
            else
                o1 = l + 1, e1 = l, m = -1;
            if (r % 2)
                o2 = r, e2 = r - 1;
            else
                o2 = r - 1, e2 = r;
            ans += m * (score.query(l - 1, r) -
                        (l - 1) * odd.query(o1 / 2, o2 / 2 + 1) +
                        (l - 1) * even.query(e1 / 2 - 1, e2 / 2));
        } else {
            m = r - a[l];
            if (l % 2) {
                odd.update(l / 2 + 1, m);
                score.update(l, l * m);
            } else {
                even.update(l / 2, m);
                score.update(l, l * (-m));
            }
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
