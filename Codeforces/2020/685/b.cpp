#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, q, l, r;
        cin >> n >> q;
        string s;
        cin >> s;
        while (q--) {
            cin >> l >> r;
            --l, --r;
            bool ok = false;
            for (int i = 0; i < l; i++)
                if (s[i] == s[l])
                    ok = true;
            for (int i = r + 1; i < n; i++)
                if (s[i] == s[r])
                    ok = true;
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
    return 0;
}