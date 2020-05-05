#include <bits/stdc++.h>
using namespace std;
// zero-indexed, [i, r)
constexpr const int MAXN = 1e5;
int mx[MAXN << 2];
void update(int idx, int l, int r, int i, int v) {
    if (r - l == 1) {
        mx[idx] = v;
        // sum: sum[idx] += d;
        return;
    }
    int m = (l + r) / 2, left = 2 * idx + 1, right = left + 1;
    if (i < m)
        update(left, l, m, i, v);
    else
        update(right, m, r, i, v);
    // sum: sum[idx] = sum[left] + sum[right]
    mx[idx] = max(mx[left], mx[right]);
}
int query(int idx, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return mx[idx];
    int m = (l + r) / 2, left = 2 * idx + 1, right = left + 1;
    if (qr <= m)
        return query(left, l, m, ql, qr);
    if (m <= ql)
        return query(right, m, r, ql, qr);

    // sum: return query(left) + query(right)
    return max(query(left, l, m, ql, qr), query(right, m, r, ql, qr));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(mx, 0, sizeof(mx));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        update(0, 0, n, i, v);
    }
    while (m--) {
        int act, a, b;
        cin >> act >> a >> b;
        if (act == 1) {  // update
            update(0, 0, n, a - 1, b);
        } else {
            cout << query(0, 0, n, a - 1, b) << '\n';
        }
    }
}
