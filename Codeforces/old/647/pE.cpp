#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1)
            res = (1LL * res * x) % MOD;
        x = (1LL * x * x) % MOD;
        y >>= 1;
    }
    return res;
}
const int mxn = 1e6 + 100;
int cnt[mxn];
void solve() {
    int n, p, mxa = 0, used;
    cin >> n >> p;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        cnt[a]++;
        mxa = max(a, mxa);
    }
    used = mxa;
    for (; mxa >= 0; mxa--) {
        if (cnt[mxa] & 1)
            break;
    }
    int d1 = 0, d2 = 0;
    for (int i = 0; i < mxa; i++) {
        if (cnt[i] >= p) {
            cnt[i + 1] += cnt[i] / p;
            cnt[i] %= p;
        }
        // while (cnt[i] >= p) {
        // cnt[i] -= p;
        //++cnt[i + 1];
        //}
    }
    if ((cnt[mxa] & 1) == 0) {
        for (mxa--; mxa >= 0; mxa--) {
            if (cnt[mxa] & 1)
                break;
        }
    }
    d1 = (1LL * power(p, mxa)) % MOD;
    for (int i = mxa - 1; i >= 0; i--) {
        if (cnt[i]) {
            int mu = (1LL * cnt[i] * power(p, i)) % MOD;
            d2 = (d2 + mu) % MOD;
        }
    }
    cout << ((d1 - d2) % MOD + MOD) % MOD << '\n';
    memset(cnt, 0, 4 * used);

    /*
    for (int i = 0; i <= mxa; i++) {
        cout << cnt[i] << " ";
    }
    cout << endl;
    int i;
    for (i = mxa; i >= 0; i--) {
        if (cnt[i] & 1)
            break;
    int d1 = power(p, i);
    int d2 = 0;
    for (i = i - 1; i >= 0; i--)
        if (cnt[i]) {
            int mu = (1LL * power(p, i) * cnt[i]) % MOD;
            d2 = (d2 + mu) % MOD;
        }
    int ans = d1 - d2;
    while (ans >= MOD)
        ans -= MOD;
    while (ans < 0)
        ans += MOD;
    cout << ans << '\n';
    */
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
    return 0;
}
