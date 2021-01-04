#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<array<int, 3>> a(n);
        for (int i = 0, h, w; i < n; i++) {
            cin >> h >> w;
            a[i] = {h, w, i};
        }
        set<array<int, 2>> seen;
        vector<int> ans(n, -1);
        sort(a.begin(), a.end(), [](const auto& x, const auto& y){
            return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0];
        });
        for (int i = 0; i < n; i++) {
            auto it = seen.upper_bound(array<int, 2>{a[i][1], -1});
            if (it != seen.begin())
                ans[a[i][2]] = (*--it)[1] + 1;
            seen.insert({a[i][1], a[i][2]});
        }
        auto b = a;
        sort(a.begin(), a.end(), [](const auto& x, const auto& y){
            return x[1] == y[1] ? x[0] > y[0] : x[1] < y[1];
        });
        seen.clear();
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && a[j][1] < b[i][0]) {
                seen.insert({a[j][0], a[j][2]});
                j++;
            }
            if (ans[b[i][2]] != -1) continue;
            auto it = seen.upper_bound(array<int, 2>{b[i][1], -1});
            if (it != seen.begin())
                ans[b[i][2]] = (*--it)[1] + 1;
        }
        for (int &it : ans)
            cout << it << ' ';
        cout << '\n';
    }
}
