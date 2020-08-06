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
    vector<int> color(n), v[2];
    int groups = 0;
    for (int i = 0; i < n; i++) {
        int c = s[i] - '0';
        if (v[c ^ 1].empty()) {
            color[i] = ++groups;
            v[c].push_back(groups);
        } else {
            int g = v[c ^ 1].back();
            color[i] = g;
            v[c ^ 1].pop_back();
            v[c].push_back(g);
        }
    }
    cout << groups << '\n';
    for (int c : color)
        cout << c << ' ';
    cout << '\n';
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