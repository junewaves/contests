#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &it : a) cin >> it;
    int ans[10], imin[10], imax[10], jmin[10], jmax[10];
    vector<int> row[10], col[10];
    for (int i = 0; i < 10; i++) {
        ans[i] = 0;
        imin[i] = jmin[i] = n + 1000;
        imax[i] = jmax[i] = -1000;
        row[i].assign(n, -1);
        col[i].assign(n, -1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int d = a[i][j] - '0';
            if (row[d][i] == -1)
                row[d][i] = j;
            else
                ans[d] = max(ans[d], (j-row[d][i])*max(i, n-1-i));
            if (col[d][j] == -1)
                col[d][j] = i;
            else
                ans[d] = max(ans[d], (i-col[d][j])*max(j, n-1-j));
            imin[d] = min(imin[d], i);
            jmin[d] = min(jmin[d], j);
            imax[d] = max(imax[d], i);
            jmax[d] = max(jmax[d], j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int d = a[i][j] - '0';
            int ibase = max(i, n-1-i);
            int jbase = max(j, n-1-j);
            ans[d] = max({ans[d], (i-imin[d]) * jbase, (imax[d]-i) * jbase, 
                                  (j-jmin[d]) * ibase, (jmax[d]-j) * ibase});
        }
    }
    for (int i = 0; i < 10; i++) 
        cout << ans[i] << " \n"[i == 9];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}