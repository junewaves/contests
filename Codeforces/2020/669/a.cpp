#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int cnt[2] = {};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    if (cnt[0] >= cnt[1]) {
        cout << cnt[0] << '\n';
        for (int i = 1; i <= cnt[0]; i++)
            cout << 0 << " \n"[i == cnt[0]];
    } else {
        if (cnt[1] & 1) cnt[1]--;
        cout << cnt[1] << '\n';
        for (int i = 1; i <= cnt[1]; i++)
            cout << 1 << " \n"[i == cnt[1]];
    }
} 

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}