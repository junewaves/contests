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
    cin >> n;
    vector<int> a(n);
    for (int& it : a)
        cin >> it;
    bool same = true;
    for (int i = 1; i < n; i++)
        if (a[i] != a[0])
            same = false;
    cout << (same ? n : 1) << '\n';
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