#include <bits/stdc++.h>
using namespace std;

struct segTree {
    int N;
    vector<vector<int>> val;
    segTree(int _n, vector<int>& g) : N(_n) {
        // initialize array
        val.resize(2 * N);
        for (int i = 0; i < (int)g.size(); i++) {
            val[i + N].push_back(g[i]);
        }
        // build tree
        for (int u = N - 1; u > 0; u--) {
            vector<int> &L = val[u << 1], &R = val[u << 1 | 1];
            int i = 0, j = 0, n = L.size(), m = R.size();
            val[u].reserve(n + m);
            while (i < n || j < m) {
                if (j == m || (i < n && L[i] < R[j]))
                    val[u].push_back(L[i++]);
                else
                    val[u].push_back(R[j++]);
            }
        }
    }
    int query(int l, int r, int lim) {
        int res = 0;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) {
                res += val[l].end() - 
                       lower_bound(val[l].begin(), val[l].end(), lim);
                l++;
            }
            if (r & 1) {
                r--;
                res += val[r].end() - 
                       lower_bound(val[r].begin(), val[r].end(), lim);
            }
        }
        return res;
    }
};

struct BIT {
    vector<int> s;
    BIT(int n) : s(n) {}
    void update(int pos, int dif) { // a[pos] += dif
		for (; pos < (int)s.size(); pos |= pos + 1) 
            s[pos] += dif;
	}
    int query(int pos) { // sum of values in [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) 
            res += s[pos-1];
		return res;
	}
};

constexpr int INF = 1e9 + 500;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& it : a) cin >> it;
    vector<int> g(n);
    vector<int> pre(n + 1);
    int cnt = 0;
    BIT bit(n);
    for (int i = 0; i < n; i++) {
        int d = i + 1 - a[i];
        pre[i + 1] = pre[i];
        if (d == 0) {
            bit.update(0, 1);
            bit.update(cnt + 1, -1);
            g[i] = cnt++;
            pre[i + 1]++;
        } else if (d > 0) {
            int l = 0, r = cnt;
            while (l < r) {
                int m = (l + r + 1) / 2;
                if (bit.query(m + 1) < d)
                    r = m - 1;
                else
                    l = m;
            }
            if (l > 0 || bit.query(l + 1) >= d) {
                bit.update(0, 1);
                bit.update(l + 1, -1);
                g[i] = l;
            } else {
                g[i] = -INF;
            }
        } else {
            g[i] = -INF;
        }
    }
    segTree st(n, g);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, n - r, pre[l]) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
/*
2 2 3 9 5 4 6 5 7 8 3 11 13
- 0 0 - 0 2 1 3 2 2 8  1  0



*/