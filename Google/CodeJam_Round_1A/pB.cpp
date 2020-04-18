// Code Jam Round 1A (4/11)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
int _n, N;
ll pa[501][501];
pair<int, int> S[501];
bool stop_dfs;
int pascal(int r, int k) {
    static int mr = 1;
    if (mr >= r)
        return pa[r][k];
    for (int i = mr + 1, j; i <= r; i++) {
        for (j = 0; j <= i; j++) {
            pa[i][j] = pa[i - 1][j] + pa[i - 1][j - 1];
        }
    }
    mr = r;
    return pa[r][k];
}
bool find(pair<int, int> v, int dep) {
    for (int i = 0; i < dep; i++) {
        if (S[i] == v)
            return true;
    }
    return false;
}
void dfs(int r, int k, ll sum, int dep) {  // dep := depth
    if (dep >= 500)
        return;
    vector<pair<int, int>> E = { { r - 1, k - 1 }, { r - 1, k },
                                 { r, k - 1 },     { r, k + 1 },
                                 { r + 1, k },     { r + 1, k + 1 } };
    for (const auto& v : E) {
        if (v.first > 0 && v.second > 0 && v.first >= v.second &&
            !find(v, dep) && !stop_dfs) {
            S[dep + 1] = v;
            ll ps = sum + pascal(v.first, v.second);
            if (ps == N) {
                stop_dfs = true;
                for (int i = 1; i <= dep + 1; i++) {
                    cout << S[i].first << " " << S[i].second << endl;
                }
            } else if (ps > N) {
                return;
            }
            dfs(v.first, v.second, ps, dep + 1);
        }
    }
}
void solve() {
    cin >> N;
    stop_dfs = false;
    // int i = 0, j = 0;
    // while (!stop_dfs) {
    dfs(0, 0, 0, 0);
    // i++, j++;
    // }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(pa, 0, sizeof(pa));
    pa[1][1] = 1;
    cin >> _n;
    for (int _cn = 1; _cn <= _n; _cn++) {
        cout << "Case #" << _cn << ": \n";
        solve();
    }
    return 0;
}