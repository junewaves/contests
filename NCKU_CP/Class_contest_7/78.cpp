#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, MOD;
vector<vector<int>> a(3, vector<int>(3)), b(3, vector<int>(1));
int m_mul(int x, int y) {
    return 1LL * x * y % MOD;
}
int m_mul(int x, int y, int tails, ...) {
    return m_mul(m_mul(x, y), tails);
}
int m_add(int x, int y) {
    int res = x + y;
    if (res >= MOD)
        res -= MOD;
    if (res < 0)
        res += MOD;
    return res;
}
int m_add(int x, int y, int tails, ...) {
    return m_add(m_add(x, y), tails);
}
// matrix multiplication
vector<vector<int>> mat_mul(const vector<vector<int>>& x,
                            const vector<vector<int>>& y) {
    int n = x.size(), m = y[0].size(), r = x[0].size();
    assert(r == (int)y.size());
    vector<vector<int>> tmp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < r; k++)
                tmp[i][j] = m_add(tmp[i][j], m_mul(x[i][k], y[k][j]));

    return tmp;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> N >> MOD;
        ll lim = 1;
        while (lim <= N)
            lim *= 10;
        b[0][0] = 0, b[1][0] = 1, b[2][0] = 1;
        for (ll x = 10; x <= lim; x *= 10) {
            // reset a
            a[0][0] = x % MOD;
            a[0][1] = a[1][1] = a[1][2] = a[2][2] = 1;
            a[0][2] = a[1][0] = a[2][0] = a[2][1] = 0;
            // matrix exponential
            ll p = min(x - 1, (ll)N) - x / 10 + 1;
            while (p) {
                if (p & 1)
                    b = mat_mul(a, b);
                a = mat_mul(a, a);
                p /= 2;
            }
        }
        cout << b[0][0] << '\n';
    }
    return 0;
}