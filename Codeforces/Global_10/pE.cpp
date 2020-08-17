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
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            ll st = 1LL << (i - 1);
            cout << st;
            for (int j = 1; j < n; j++)
                cout << " " << (st << j);
        } else {
            cout << "0";
            for (int j = 1; j < n; j++)
                cout << " 0";
        }
        cout << endl;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll k;
        cin >> k;
        int x = 1, y = 1;
        for (int j = 1; j < n * 2; j++) {
            cout << x << ' ' << y << endl;
            if ((k ^ x) & 1)
                y++;
            else
                x++;
            k >>= 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}