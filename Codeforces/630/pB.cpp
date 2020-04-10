#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
typedef long long int ll;
int n, a[1000], color[1000], p[11] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
void solve() {
    memset(a, 0, sizeof(a));
    memset(color, 0, sizeof(color));
    vector<int> g[11];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 11; j++) {
            if (a[i] % p[j] == 0) {
                g[j].push_back(i);
                break;
            }
        }
    }
    int c = 0;
    for (int i = 0; i < 11; i++) {
        if (g[i].size() > 0) {
            c++;
            for (int j = 0; j < g[i].size(); j++) {
                color[g[i][j]] = c;
            }
        }
    }
    cout << c << endl;
    for (int i = 0; i < n; i++) {
        cout << color[i] << " \n"[i == n - 1];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
}