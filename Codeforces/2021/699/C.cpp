#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n), c(m);
        for (int &it : a) cin >> it;
        for (int &it : b) cin >> it;
        for (int &it : c) cin >> it;

        vector<int> no_change(n, -1);
        vector<vector<int>> need_paint(n);
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i])
                need_paint[b[i] - 1].push_back(i);
            else 
                no_change[b[i] - 1] = i;
        }
        
        int buf = -1;
        bool fail = false;
        vector<int> ans(m);
        for (int i = m - 1; i >= 0; i--) {
            int color = c[i] - 1;
            if (need_paint[color].size()) {
                ans[i] = need_paint[color].back();
                buf = need_paint[color].back();
                need_paint[color].pop_back();
            } else if (no_change[color] >= 0) {
                ans[i] = no_change[color];
                buf = no_change[color];
            } else if (buf != -1) {
                ans[i] = buf;
            } else {
                fail = true;
                break;
            }
        }
        for (int i = 0; i < n; i++)
            fail = fail || need_paint[i].size() > 0u;

        if (!fail) {
            cout << "YES\n";
            for (int it : ans)
                cout << it + 1 << ' ';
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
