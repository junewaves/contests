#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int64_t first;
        cin >> first;
        set<pair<int64_t, int>> s;
        for (int i = 2; i <= n; i++) {
            int64_t x;
            cin >> x;
            s.emplace(x, i);
        }
        bool fail = false;
        vector<tuple<int, int, int64_t>> ans;
        ans.reserve(2 * n);
        for (int i = 1; i < n; i++) {
            auto [val, idx] = *s.begin();
            s.erase(s.begin());
            if (val > first) {
                if (s.empty()) {
                    fail = true;
                    break;
                }
                int64_t diff = val - first;
                auto [nval, nidx] = *s.begin();
                s.erase(s.begin());
                ans.emplace_back(idx, nidx, diff);
                val -= diff;
                nval += diff;
                s.emplace(nval, nidx);
            }
            ans.emplace_back(idx, 1, val);
            first += val;
        }
        if (fail) {
            cout << "-1\n";
        } else {
            cout << ans.size() << '\n';
            for (auto [p, q, x] : ans)
                cout << p << ' ' << q << ' ' << x << '\n';
        }
    }

    return 0;
}
