#include <bits/stdc++.h>
using namespace std;

constexpr int64_t inf = 1e18l;
int64_t x, y;
map<int64_t, int64_t> mp;

int64_t rec(int64_t v) {
    if (auto it = mp.find(v); it != mp.end())
        return it->second;
    mp[v] = inf;
    int64_t &ans = mp[v];
    ans = min(ans, abs(v - x));
    if (v == 1)
        return ans;
    if (v % 2 == 0)
        ans = min(ans, rec(v >> 1) + 1);
    else
        ans = min(ans, min(rec(v + 1), rec(v - 1)) + 1);
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> x >> y;
    cout << rec(y);
    return 0;
}