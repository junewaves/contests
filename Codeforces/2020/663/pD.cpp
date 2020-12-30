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
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    if (n >= 4) {
        cout << "-1\n";
        return 0;
    }
    vector<string> str(n);
    vector<unsigned int> a;
    for (auto& it : str)
        cin >> it;
    a.resize(m, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (str[j][i] == '1')
                a[i] |= 1 << j;
        }
    }
    vector<vector<int>> dp(m + 1, vector<int>(1 << n, 1e9));
    int tr[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tr[i][j] = __builtin_popcount(i ^ j);
        }
    }
    fill(dp[0].begin(), dp[0].end(), 0);
    int mask[2] = {n == 2 ? 1 : 5, 2};
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < (1 << n); j++) {
            for (int k : {0, 1}) {
                int t = j ^ mask[k];
                dp[i][t] = min(dp[i][t], dp[i - 1][j] + tr[a[i - 1]][t]);
            }
        }
    }
    cout << *min_element(dp[m].begin(), dp[m].end()) << '\n';;
    return 0;
}