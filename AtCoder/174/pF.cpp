#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

struct BIT {
    int mxn;
    vector<int> t;
    BIT(int _n) : mxn(_n), t(_n, 0) {}
    void add(int i, int d) {
        for (; i < mxn; i += i & -i) {
            t[i] += d;
        }
    }
    int get(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i) {
            res += t[i];
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), last_seen(n + 1, n + 1);
    for (int& it : a)
        cin >> it;
    BIT ft(n + 5);
    vector<int> answers(q, -1);
    vector<vector<pair<int, int>>> query_at(n + 1);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        query_at[l].emplace_back(r, i);
    }
    for (int l = n; l > 0; l--) {
        ft.add(last_seen[a[l - 1]], -1);
        ft.add(l, 1);
        last_seen[a[l - 1]] = l;
        for (auto [r, i] : query_at[l])
            answers[i] = ft.get(r);
    }
    for (int ans : answers)
        cout << ans << '\n';
    return 0;
}