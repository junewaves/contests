#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const ll inf = 4e18;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        vector<pair<int, ll>> ops = { { 2, a }, { 3, b }, { 5, c } };
        unordered_map<ll, ll> mp;
        mp[0] = 0;
        mp[1] = d;
        function<ll(ll)> dfs = [&](ll x) {
            if (mp.find(x) != mp.end()) {
                return mp[x];
            }
            ll ret = inf;
            if ((long double)d * (long double)x < ret) {
                ret = d * x;
            }
            for (auto& p : ops) {
                int n = p.first;
                ll c = p.second;
                ret = min(ret, dfs(x / n) + c + d * (x % n));
                if (x % n != 0)
                    ret = min(ret, dfs(x / n + 1) + c + d * (n - x % n));
            }
            return mp[x] = ret;
        };
        cout << dfs(n) << '\n';
    }
}
