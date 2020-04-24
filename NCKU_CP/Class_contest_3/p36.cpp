#include <bits/stdc++.h>
using namespace std;
//#ifndef _LOCAL_DEBUG
//#define endl '\n'
//#endif
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    list<ll> m;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        m.push_back(t);
    }
    ll a, b, s, sum = 0;
    while (m.size() > 1) {
        auto it = m.begin(), it2 = it;
        s = LONG_LONG_MAX;
        a = *it;
        // cout << a << " ";
        for (it++; it != m.end(); it++) {
            b = *it;
            // cout << b << " ";
            if (a + b < s) {
                s = a + b;
                it2 = it;
            }
            a = b;
        }
        sum += s;
        *it2 = s;
        it2--;
        m.erase(it2);
    }
    cout << sum << endl;
}
