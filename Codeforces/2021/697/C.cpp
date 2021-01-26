#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, k;
        cin >> a >> b >> k;
        vector<int> va(k), vb(k), ca(a), cb(b);
        for (int &it : va) cin >> it, --it;
        for (int &it : vb) cin >> it, --it;
        int64_t ans = 0;
        for (int i = 0; i < k; i++) {
            int x = va[i], y = vb[i];
            ans += i - ca[x] - cb[y];
            ca[x]++;
            cb[y]++;
        }
        cout << ans << '\n';
    }
    return 0;
}
