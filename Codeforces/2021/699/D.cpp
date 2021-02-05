#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &s : a) cin >> s;

    if (m % 2 == 1) {
        cout << "YES\n";
        for (int rep = 0; rep <= m; rep++)
            cout << 1 + (rep & 1) << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] == a[j][i]) {
                cout << "YES\n";
                for (int rep = 0; rep <= m; rep++) 
                    cout << (rep & 1 ? j : i) + 1 << ' ';
                cout << '\n';
                return;
            }
        }
    }

    if (n >= 3) {
        array<int, 3> p{0, 1, 2};
        while (a[p[0]][p[1]] != a[p[1]][p[2]])
            next_permutation(p.begin(), p.end());
        assert(a[p[0]][p[1]] == a[p[1]][p[2]]);
        cout << "YES\n";
        vector<int> ans(m + 1);
        int mid = m / 2;
        ans[mid] = p[1];
        for (int i = 1; i <= mid; i++) {
            ans[mid - i] = p[(i & 1) ? 0 : 1];
            ans[mid + i] = p[(i & 1) ? 2 : 1];
        }
        for (int it : ans)
            cout << it + 1 << ' ';
        cout << '\n';
        return;
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
