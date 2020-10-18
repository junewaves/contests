#include <bits/stdc++.h>
using namespace std;

constexpr int di[6] = {1, 0, -1, -1,  0, 1};
constexpr int dj[6] = {1, 1,  0, -1, -1, 0};

void solve() {
    int64_t x, y;
    cin >> x >> y;
    int64_t cost[6], tmp[6];
    for (int i = 0; i < 6; i++)
        cin >> cost[i];

    for (int i = 0; i < 6; i++) {
        int prv = i == 0 ? 5 : i - 1;
        int nxt = i == 5 ? 0 : i + 1;
        tmp[i] = cost[prv] + cost[nxt];
    }
    for (int i = 0; i < 6; i++) {
        if (cost[i] > tmp[i]) {
            cost[i] = tmp[i];
        }
    }
    int64_t ans = 0;
    if (x >= 0 && y >= 0) {
        int64_t s = min(x, y);
        x -= s, y -= s;
        ans = s * cost[0] + x * cost[5] + y * cost[1];
    } else if (x < 0 && y < 0) {
        x = -x, y = -y;
        int64_t s = min(x, y);
        x -= s, y -= s;
        ans = s * cost[3] + x * cost[2] + y * cost[4];
    } else {
        if (x >= 0) {
            ans += x * cost[5];
        } else {
            ans += -x * cost[2];
        }
        if (y >= 0) {
            ans += y * cost[1];
        } else {
            ans += -y * cost[4];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
} 