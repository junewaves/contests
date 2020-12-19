#include <bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> t;
    BIT(int n) : t(n) {}
    void add(int i, int x) {
        for (; i < int(t.size()); i |= i + 1)
            t[i] += x;
    }
    int64_t sum(int i) {
        int64_t r = 0;
        for (i++; i > 0; i &= i - 1)
            r += t[i - 1];
        return r;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> min_right(h, w), min_down(w, h);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        min_right[x] = min(min_right[x], y);
        min_down[y] = min(min_down[y], x);
    }
    BIT bit(w + 1);
    int64_t ans = 1;
    vector<pair<int, int>> row, col;
    for (int i = 1; i < min_down[0]; i++) {
        ans += min_right[i];
        row.emplace_back(i, min_right[i]);
    }
    for (int i = 1; i < min_right[0]; i++) {
        ans += min_down[i];
        col.emplace_back(min_down[i], i);
    }
    sort(col.begin(), col.end());
    int cnt = 0, sz = row.size();
    for (auto [x, y] : col) {
        while (cnt < sz && row[cnt].first < x) {
            bit.add(row[cnt].second, 1);
            cnt++;
        }
        ans -= cnt - bit.sum(y);
    }
    cout << ans << '\n';
    return 0;
}