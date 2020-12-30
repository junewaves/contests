#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

typedef tuple<int, int, int, int> Event;
constexpr int bound = 1e6;
struct BIT {
    vector<int> t = vector<int>(bound + 5);
    void update(int i, int d) {
        for (i += 1; i < bound + 5; i += i & -i)
            t[i] += d;
    }
    int query(int i) {
        int res = 0;
        for (i += 1; i > 0; i -= i & -i) 
            res += t[i];
        return res;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nh, nv;
    cin >> nh >> nv;
    vector<Event> h;
    h.reserve(nh * 2 + nv);
    ll ans = 0;
    for (int i = 0; i < nh; i++) {
        int y, x1, x2;
        cin >> y >> x1 >> x2;
        if (x2 - x1 == bound)
            ans++;
        h.emplace_back(x1, 0, y, 1);
        h.emplace_back(x2 + 1, 0, y, -1);
    }
    for (int i = 0; i < nv; i++) {
        int x, y1, y2;
        cin >> x >> y1 >> y2;
        if (y2 - y1 == bound)
            ans++;
        h.emplace_back(x, 1, y1, y2);
    }
    sort(h.begin(), h.end());
    BIT bit;
    for (auto [x, t, y1, y2] : h) {
        if (t == 0)
            bit.update(y1, y2);
        else
            ans += bit.query(y2) - bit.query(y1 - 1);
    }
    cout << ans + 1 << '\n';
    return 0;
}