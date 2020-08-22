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
    vector<int> b = a;
    sort(b.begin(), b.end());
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i] && a[i] % b[0] != 0) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
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