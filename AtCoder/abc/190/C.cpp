#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    int k;
    cin >> k;
    vector<int> c(k), d(k);
    for (int i = 0; i < k; i++) {
        cin >> c[i] >> d[i];
        c[i]--, d[i]--;
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << k); mask++) {
        vector<bool> dish(n);
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i))
                dish[c[i]] = true;
            else
                dish[d[i]] = true;
        }
        int cnt = 0;
        for (int i = 0; i < m; i++)
            cnt += (dish[a[i]] && dish[b[i]]);

        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}
