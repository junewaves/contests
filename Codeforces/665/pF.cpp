#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

constexpr int mxn = (1 << 18) + 10;

struct BIT {
    vector<ll> t = vector<ll>(mxn);
    void update(int i, int d) {
        for (i += 1; i < mxn; i += i & -i)
            t[i] += d;
    }
    ll query(int i) {
        ll res = 0;
        for (i += 1; i > 0; i -= i & -i) 
            res += t[i];
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int logn, q, n;
    BIT bit;
    cin >> logn >> q;
    n = 1 << logn;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        bit.update(i, a[i]);
    }
    int changes = 0;
    while (q--) {
        int act;
        cin >> act;
        if (act == 1) {
            // replace
            int x, k;
            cin >> x >> k;
            int i = (x - 1) ^ changes;
            bit.update(i, k - a[i]);
            a[i] = k;
        } else if (act == 2) {
            // reverse
            int k;
            cin >> k;
            changes ^= (1 << k) - 1;
        } else if (act == 3) {
            // swap
            int k;
            cin >> k;
            changes ^= (1 << k);
        } else {
            // sum
            int l, r;
            cin >> l >> r;
            l--, r--;
            stack<pair<int, int>> st;
            // split [l, r] into segments with len = 2^k
            st.emplace(0, n - 1);
            ll ans = 0;
            while (st.size()) {
                auto [L, R] = st.top();
                st.pop();
                if (R < l || r < L)
                    continue;
                if (l <= L && R <= r) {
                    if (int k = R - L + 1; changes >= k) {
                        k *= changes / k;
                        R ^= k;
                        L ^= k;
                    }
                    ans += bit.query(R) - bit.query(L - 1);
                    continue;
                }
                int M = (L + R) / 2;
                st.emplace(M + 1, R);
                st.emplace(L, M);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}