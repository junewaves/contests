#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (n < 2 || m < 2) {
        cout << "0\n";
        return 0;
    }
    if (n >= 4 && m >= 4) {
        cout << "-1\n";
        return 0;
    }
    vector<string> a(n);
    for (auto& it : a)
        cin >> it;
    if (m > n) {
        vector<string> tmp = a;
        a.clear();
        for (int i = 0; i < m; i++) {
            string& s = a.emplace_back();
            for (int j = 0; j < n; j++) {
                s += tmp[j][i];
            }
        }
        swap(n, m);
    }
    vector<vector<int>> dp(n + 1, vector<int>(1 << m, 1e9));
    fill(dp[0].begin(), dp[0].end(), 0);
    int m1 = m == 2 ? 1 : 5, m2 = 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << m); j++) {
            int a1 = 0, a2 = 0, t1 = j ^ m1, t2 = j ^ m2;
            for (int k = 0; k < m; k++) {
                a1 += a[i - 1][k] == (t1 & (1 << k) ? '0' : '1');
            }
            dp[i][t1] = min(dp[i][t1], dp[i - 1][j] + a1);
            for (int k = 0; k < m; k++) {
                a2 += a[i - 1][k] == (t2 & (1 << k) ? '0' : '1');
            }
            dp[i][t2] = min(dp[i][t2], dp[i - 1][j] + a2);
        }
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';;
    return 0;
}