#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
const int mxN = 2e5 + 5;
ll power[mxN];
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    power[0] = 1;
    for (int i = 1; i < mxN; i++) {
        power[i] = power[i - 1] * 2 % Mod;
    }
    int n;
    cin >> n;
    ll special = 0;
    map<pair<ll, ll>, pair<int, int>> mp;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        if (a == 0LL && b == 0LL) {
            special++;
            continue;
        }
        if (make_pair(a, b) < make_pair(0ll, 0ll))
            a = -a, b = -b;
        ll g = gcd(abs(a), abs(b));
        a = a / g, b = b / g;
        if (b > 0)
            mp[{ a, b }].first++;
        else
            mp[{ -b, a }].second++;
    }

    ll ans = 1;
    for (auto& p : mp) {
        ans = ans * (power[p.second.first] + power[p.second.second] - 1) % Mod;
    }
    cout << (ans - 1 + special + Mod) % Mod << '\n';
}
