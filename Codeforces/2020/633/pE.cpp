// Codeforces Round #633 (Div. 2) (4/12)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
unordered_set<ll> s = { 1, 2, 3 };
vector<ll> v = { 1, 2, 3 };
void solve() {
    ll n;
    cin >> n;
    for (ll i = v[v.size() - 3]; (ll)v.size() < n; i++) {
        if (s.count(i))
            continue;
        ll j = i;
        while (1) {
            j++;
            if (s.count(j))
                continue;
            ll k = i ^ j;
            if (k <= i || k <= j || s.count(k))
                continue;
            else {
                s.insert({ i, j, k });
                v.push_back(i);
                v.push_back(j);
                v.push_back(k);
                break;
            }
        }
    }
    cout << v[n - 1] << endl;
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