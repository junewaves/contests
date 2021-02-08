#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &s : a) cin >> s;

    int ans = 0;
    for (int rep : {0, 1}) {
        for (int i = 0; i < n - 1; i++) {
            bool prv = false;
            for (int j = 0; j < m - 1; j++) {
                if (a[i][j] == '.' && a[i + 1][j] == '#') {
                    if (!prv) {
                        ans++;
                        prv = true;
                    }
                } else {
                    prv = false;
                }
            }
        }
        for (int j = 0; j < m - 1; j++) {
            bool prv = false;
            for (int i = 0; i < n - 1; i++) {
                if (a[i][j] == '.' && a[i][j + 1] == '#') {
                    if (!prv) {
                        ans++;
                        prv = true;
                    }
                } else {
                    prv = false;
                }
            }
        }
        if (rep == 0) {
            for (auto &s : a)
                for (auto &c : s)
                    c ^= ('.' ^ '#');
        }
    }
    cout << ans << '\n';
    return 0;
}
