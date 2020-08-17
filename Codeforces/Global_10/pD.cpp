#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> g;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1])
            cnt++;
        else
            g.push_back(cnt), cnt = 1;
    }
    if (s[n - 1] == s[0] && g.size())
        g[0] += cnt;
    else
        g.push_back(cnt);
    int ans = 0;
    if ((int)g.size() == 1)
        ans = (g[0] + 2) / 3;
    else {
        for (int c : g) {
            ans += c / 3;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}