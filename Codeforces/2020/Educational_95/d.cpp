#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& it : a) cin >> it;
    sort(a.begin(), a.end());
    int mn = a[0], mx = a[n - 1];
    set<int> s(a.begin(), a.end());
    multiset<int> d;
    for (int i = 1; i < n; i++) {
        d.insert(a[i] - a[i - 1]);
    }
    if (n >= 2)
        cout << mx - mn - *d.rbegin() << '\n';
    else
        cout << 0 << '\n';
    while (q--) {
        int i, x;
        cin >> i >> x;
        if (i == 0) {
            if (n <= 2) {
                s.erase(x);
                if (n == 2) {
                    d.clear();
                    mx = mn = *s.begin();
                }
            } else {
                auto it = s.find(x);
                auto nxt = next(it);
                if (nxt == s.end()) {
                    mx = *prev(it);
                    d.erase(d.find(x - mx));
                } else if (it == s.begin()) {
                    mn = *nxt;
                    d.erase(d.find(mn - x));
                } else {
                    auto prv = prev(it);
                    int l = *prv, r = *nxt;
                    d.erase(d.find(x - l));
                    d.erase(d.find(r - x));
                    d.insert(r - l);
                }
                s.erase(it);
            }
            n--;
        } else {
            if (s.empty()) {
                mx = mn = x;
            } else if (x > *s.rbegin()) {
                d.insert(x - *s.rbegin());
                mx = x;
            } else if (x < *s.begin()) {
                d.insert(*s.begin() - x);
                mn = x;
            } else {
                auto it = s.lower_bound(x);
                auto prv = prev(it);
                int od = *it - *prv;
                d.erase(d.find(od));
                d.insert(x - *prv);
                d.insert(*it - x);
            }
            s.insert(x);
            n++;
        }
        if (n >= 2)
            cout << mx - mn - *d.rbegin() << '\n';
        else
            cout << 0 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}