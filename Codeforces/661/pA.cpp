#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

int cnt[100];
void solve() {
    int n;
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cnt[t - 1]++;
    }
    int i = 0;
    while (i < 100 && cnt[i] == 0)
        i++;
    while (i < 100 && cnt[i] != 0)
        i++;
    while (i < 100 && cnt[i] == 0)
        i++;
    if (i != 100)
        cout << "NO\n";
    else 
        cout << "YES\n";
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