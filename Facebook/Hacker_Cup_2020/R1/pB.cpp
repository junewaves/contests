#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> read_vector(int n, int k) {
    int A, B, C, D;
    vector<int> res(n);
    for (int i = 0; i < k; i++)
        cin >> res[i];
    cin >> A >> B >> C >> D;
    for (int i = k; i < n; i++)
        res[i] = ((ll)A * res[i - 2] + (ll)B * res[i - 1] + C) % D + 1;
    sort(res.begin(), res.end());
    return res;
}

void solve() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    auto p = read_vector(n, k);
    auto q = read_vector(m, k);
    int lo = 0, hi = 2e9 + 5;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int idx = 0;
        for (int x : p) {
            if (idx == m)
                break;
            int L = q[idx];
            while (idx < m) {
                int R = q[idx], need = 0;
                if (x <= L)
                    need = R - x;
                else if (R <= x)
                    need = x - L;
                else
                    need = R - L + min(R - x, x - L);

                if (need <= mid)
                    idx++;
                else
                    break;
            }
        }
        if (idx == m)
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    for (int cn = 1; cn <= tt; cn++) {
        cout << "Case #" << cn << ": ";
        solve();
    }
    return 0;
}