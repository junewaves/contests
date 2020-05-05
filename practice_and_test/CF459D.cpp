#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 1e6 + 6;
int n, sz = 0, a[N], bit[N], tot[N], cnt[N], rem[N];
void add(int i, int d) {
    i += 1;
    while (i < N) {
        bit[i] += d;
        i += (i & -i);
    }
}
int get(int i) {
    int res = 0;
    while (i > 0) {
        res += bit[i];
        i -= (i & -i);
    }
    return res;
}
int sum(int x, int y) {
    return get(y) - get(x);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot[sz++] = a[i];
    }
    // make tot sorted and unique
    sort(tot, tot + sz);
    sz = unique(tot, tot + sz) - tot;
    // discretization
    for (int i = 0; i < n; i++)
        a[i] = lower_bound(tot, tot + sz, a[i]) - tot;
    for (int i = n - 1; i >= 0; i--) {
        int _i = a[i];
        cnt[_i]++;
        add(cnt[_i], 1);
        rem[i] = cnt[_i];
    }
    memset(cnt, 0, sizeof(cnt));
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int _i = a[i];
        add(rem[i], -1);
        cnt[_i]++;
        ans += sum(1, cnt[_i]);
    }
    cout << ans << endl;
}
