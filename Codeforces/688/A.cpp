#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        bool go[101]{};
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            go[x] = true;
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            if (go[x]) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}