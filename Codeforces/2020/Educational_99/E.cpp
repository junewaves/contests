#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    constexpr int64_t INF = 1e9 + 100;
    int tt;
    cin >> tt;
    while (tt--) {
        array<int64_t, 4> x, y;
        for (int i = 0; i < 4; i++)
            cin >> x[i] >> y[i];
        auto check = [&](int64_t k) -> int64_t {
            array<int64_t, 4> cx = x, cy = y;
            cx[1] -= k;
            cx[3] -= k;
            cy[2] -= k;
            cy[3] -= k;
            sort(cx.begin(), cx.end());
            sort(cy.begin(), cy.end());
            int64_t cost = 0;
            for (int i = 0; i < 4; i++)
                cost += abs(cx[i] - cx[1]) + abs(cy[i] - cy[1]);
            return cost;
        };
        array<int64_t, 4> save_x = x, save_y = y;
        array<int, 4> id = {0, 1, 2, 3};
        int64_t ans = INF * INF;
        do {
            for (int i = 0; i < 4; i++) {
                x[i] = save_x[id[i]];
                y[i] = save_y[id[i]];
            }
            int64_t low = 0, high = INF;
            while (low < high) {
                int64_t mid = (low + high) >> 1;
                if (check(mid) < check(mid + 1))
                    high = mid;
                else 
                    low = mid + 1;
            }
            ans = min(ans, check(low));
        } while (next_permutation(id.begin(), id.end()));
        cout << ans << '\n';
    }
    return 0;
}