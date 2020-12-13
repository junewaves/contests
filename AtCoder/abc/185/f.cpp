#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> st(n * 2);
    for (int i = 0; i < n; i++)
        cin >> st[n + i];
    for (int i = n - 1; i > 0; i--)
        st[i] = st[i << 1] ^ st[i << 1 | 1];
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            for (st[x += n - 1] ^= y; x >>= 1;)
                st[x] = st[x << 1] ^ st[x << 1 | 1];
        } else {
            int res = 0;
            for (x += n - 1, y += n; x < y; x /= 2, y /= 2) {
                if (x & 1) res ^= st[x++];
                if (y & 1) res ^= st[--y];
            }
            cout << res << '\n';
        }
    }
}
