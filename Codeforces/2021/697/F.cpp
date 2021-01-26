#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    auto get_matrix = [](int n, bool input) {
        vector<vector<bool>> mat(n, vector<bool>(n));
        if (input) {
            for (int i = 0; i < n; i++) {
                string s;
                cin >> s;
                for (int j = 0; j < n; j++)
                    mat[i][j] = s[j] == '1';
            }
        }
        return mat;
    };
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        auto a = get_matrix(n, true);
        auto b = get_matrix(n, true);
        auto c = get_matrix(n, false);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                c[i][j] = a[i][j] ^ b[i][j];
        set<vector<bool>> rows;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            rows.insert(c[i]);
            if (int(rows.size()) > 2) {
                ok = false;
                break;
            }
        }
        if (ok && int(rows.size()) == 2) {
            auto r1 = *rows.begin();
            auto r2 = *prev(rows.end());
            bool first = r1[0] ^ r2[0];
            for (int i = 1; i < n; i++) {
                if ((r1[i] ^ r2[i]) != first) {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
