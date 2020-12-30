#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 1; i < int(s.size()); i++) {
            if (s[i] == s[i - 1] || (i >= 2 && s[i] == s[i - 2])) {
                ans++;
                s[i] = '?';
            }
        }
        cout << ans <<'\n';
    }
    return 0;
}