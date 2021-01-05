#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    constexpr int mxn = 1e6;
    vector<int> pr(mxn + 1);
    for (int i = 2; i <= mxn; i += 1 + (i & 1))
        if (!pr[i])
            for (int j = i; j <= mxn; j += i)
                pr[j] = i;
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        unordered_map<int, int> cnt;
        int ans[2]{};
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            unordered_map<int, int> fp;
            while (x > 1) {
                fp[pr[x]]++;
                x /= pr[x];
            }
            int base = 1;
            for (const auto& p : fp)
                if (p.second & 1)
                    base *= p.first;
            int val = ++cnt[base];
            ans[0] = max(ans[0], val);
            if (val & 1)
                ans[1] -= val - 1;
            else
                ans[1] += val;
        }
        if (cnt.count(1) && cnt[1] & 1) 
            ans[1] += cnt[1];
        ans[1] = max(ans[0], ans[1]);
        int q;
        cin >> q;
        while (q--) {
            int64_t w;
            cin >> w;
            cout << ans[w > 0] << '\n';
        }
    }
    return 0;
}