#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, nm, lognm;
    cin >> n >> m;
    nm = n * m;
    lognm = 0;
    while ((1 << lognm) <= nm)
        ++lognm;
    vector<char> color, vis;
    vector<int> nxt, nxt2;
    color = vis = vector<char>(nm);
    nxt = nxt2 = vector<int>(nm);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            color[i * m + j] = (s[j] == '0');
        }
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0, to; j < m; j++) {
            if (s[j] == 'U')
                to = (i - 1) * m + j;
            else if (s[j] == 'D')
                to = (i + 1) * m + j;
            else if (s[j] == 'L')
                to = i * m + (j - 1);
            else if (s[j] == 'R')
                to = i * m + (j + 1);
            nxt[i * m + j] = to;
        }
    }
    for (int j = 0; j < lognm; j++) {
        for (int i = 0; i < nm; i++) {
            nxt2[i] = nxt[nxt[i]];
        }
        copy(nxt2.begin(), nxt2.end(), nxt.begin());
    }
    int all = 0, black = 0;
    for (int i = 0; i < nm; i++) {
        if (vis[nxt[i]] == 0) {
            all++;
            black += color[i];
            vis[nxt[i]] = color[i] + 1;
        } else if (vis[nxt[i]] == 1 && color[i]) {
            black++;
            vis[nxt[i]] = 2;
        }
    }
    cout << all << " " << black << '\n';
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