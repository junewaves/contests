#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> c(n, vector<int>(m + 1));
    ll min_cost = LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {
        cin >> c[i][0];
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];
    }
    for (int bit = 1; bit < (1 << n); bit++) {
        ll cost = 0;
        vector<int> level(m + 1, 0);
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                cost += c[i][0];
                for (int j = 1; j <= m; j++)
                    level[j] += c[i][j];
            }
        }
        bool ok = true;
        for (int j = 1; j <= m; j++) {
            // cout << level[j] << " ";
            if (level[j] < x) {
                ok = false;
                break;
            }
        }
        // cout << endl;
        if (ok)
            min_cost = min(min_cost, cost);
    }
    if (min_cost == LONG_LONG_MAX)
        cout << "-1";
    else
        cout << min_cost;
}
