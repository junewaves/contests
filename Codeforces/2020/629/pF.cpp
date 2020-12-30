#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
#define ll long long int
int n, k, t;
struct Stats {
    ll nBefore, nAfter, sLeft, sRight;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    map<int, int> num;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (num[t]) {
            num[t]++;
        } else
            num[t] = 1;
    }
    t = num.size();
    for (auto a : num) {
        if (a.second >= k) {
            cout << 0 << endl;
            return 0;
        }
    }
    vector<pair<int, int>> v(num.begin(), num.end());
    vector<Stats> s(t);
    num.clear();
    // for (auto p : v) {
    //     cout << p.first << ", " << p.second << endl;
    // }
    ll rsum = v[t - 1].second, lsum = v[0].second, rsteps = 0, lsteps = 0;
    s[0].nBefore = lsum;
    s[0].sLeft = 0;
    s[t - 1].nAfter = rsum;
    s[t - 1].sRight = 0;
    for (int i = 1, j = t - 2; i < t; ++i, --j) {
        lsteps += (v[i].first - v[i - 1].first) * lsum;
        lsum += v[i].second;
        rsteps += (v[j + 1].first - v[j].first) * rsum;
        rsum += v[j].second;
        s[i].nBefore = lsum;
        s[i].sLeft = lsteps;
        s[j].nAfter = rsum;
        s[j].sRight = rsteps;
    }
    // for (int x = 0; x < t; x++) {
    //     if (s[x].sLeft < 0LL || s[x].sRight < 0LL) {
    //         cout << v[x].first << ": ";
    //         cout << s[x].nBefore << ", ";
    //         cout << s[x].sLeft << ", ";
    //         cout << s[x].nAfter << ", ";
    //         cout << s[x].sRight << "\n";
    //     }
    // }

    ll min_moves = LONG_LONG_MAX;
    for (auto it = s.begin(); it != s.end(); ++it) {
        ll m;
        bool cond1 = it->nBefore >= k, cond2 = it->nAfter >= k;
        if (cond1 && cond2) {
            m = min(it->sLeft - it->nBefore, it->sRight - it->nAfter) + k;
        } else if (cond1) {
            m = it->sLeft - it->nBefore + k;
        } else if (cond2) {
            m = it->sRight - it->nAfter + k;
        } else {
            m = it->sLeft + it->sRight - n + k;
        }
        min_moves = min(min_moves, m);
    }
    cout << min_moves << endl;
    return 0;
}