#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 2e5 + 5;
int n, num[MAXN], bit[MAXN];
ll t;
vector<ll> sums(1, 0);

void update(int x) {
    for (int i = x; i < MAXN; i |= i + 1)
        ++bit[i];
}

int count(int x) {
    int res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        res += bit[i];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t;
    sums.reserve(n + 1);
    ll pre = 0;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        pre += num[i];
        sums.push_back(pre);
    }
    sort(sums.begin(), sums.end());
    sums.resize(unique(sums.begin(), sums.end()) - sums.begin());
    ll ans = 0;
    pre = 0;
    update(lower_bound(sums.begin(), sums.end(), 0) - sums.begin());
    for (int i = 0; i < n; i++) {
        pre += num[i];
        int p = upper_bound(sums.begin(), sums.end(), pre - t) - sums.begin();
        ans += (i + 1 - count(p - 1));
        int k = lower_bound(sums.begin(), sums.end(), pre) - sums.begin();
        update(k);
    }
    cout << ans << '\n';
}
