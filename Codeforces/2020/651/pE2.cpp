#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int cnt1 = 0, cnt2 = 0;
    int t0 = 0, t1 = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] == '1')
            cnt1++;
        if (s2[i] == '1')
            cnt2++;
        if (s1[i] != s2[i]) {
            if (s1[i] == '1') {
                t1++;
                if (t0 > 0) {
                    t0--;
                } else {
                    ans++;
                }
            } else {
                t0++;
                if (t1 > 0) {
                    t1--;
                } else {
                    ans++;
                }
            }
        }
    }
    if (cnt1 != cnt2)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}