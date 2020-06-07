#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int di[4] = { 1, 0, -1, 0 };
const int dj[4] = { 0, 1, 0, -1 };
int n, m;
string mp[51];
bool vis[50][50];
bool dfs(int i, int j) {
    if (i == n - 1 && j == m - 1)
        return true;
    if (mp[i][j] == '1')
        return true;
    if (mp[i][j] == 'B' || mp[i][j] == '#')
        return false;
    vis[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]) {
            if (dfs(ni, nj)) {
                mp[i][j] = '1';
                return true;
            }
        }
    }
    return false;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        mp[i].clear();
    }
    // mp = vector<string>(n);
    int g = 0, b = 0;
    // vector<pair<int, int>> good, bad;
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
        int j = 0;
        for (char c : mp[i]) {
            if (c == 'B') {
                // bad.emplace_back(i, j);
                b++;
            } else if (c == 'G') {
                // good.emplace_back(i, j);
                g++;
            }
            ++j;
        }
    }
    if (g == 0 && b == 0) {
        cout << "Yes\n";
        return;
    } else if (g == 0) {
        if (mp[n - 1][m - 1] == 'B')
            cout << "No\n";
        else
            cout << "Yes\n";
        return;
    }
    // for (const auto& p : bad) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 'B') {
                // cout << i << " " << j << endl;
                for (int k = 0; k < 4; k++) {
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    // cout << ni << " " << nj << endl;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (mp[ni][nj] == '.')
                            mp[ni][nj] = '#';
                        else if (mp[ni][nj] == 'G') {
                            cout << "No\n";
                            return;
                        }
                    }
                }
            }
        }
    }
    // for (string& s : mp)
    // cout << s << endl;
    if (mp[n - 1][m - 1] == '#') {
        cout << "No\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 'G') {
                memset(vis, 0, sizeof(vis));
                if (!dfs(i, j)) {
                    cout << "No\n";
                    return;
                }
            }
        }
    }
    cout << "Yes\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
    return 0;
}
