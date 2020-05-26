#include <bits/stdc++.h>
using namespace std;

int n, m, nm, lognm;
vector<string> color, moves;
vector<vector<bool>> vis;
vector<vector<int>> nxt;

pair<int, int> getnext(int i, int j) {
    int ni, nj;
    if (moves[i][j] == 'U')
        ni = i - 1, nj = j;
    if (moves[i][j] == 'R')
        ni = i, nj = j + 1;
    if (moves[i][j] == 'D')
        ni = i + 1, nj = j;
    if (moves[i][j] == 'L')
        ni = i, nj = j - 1;
    return make_pair(ni, nj);
}

void dfs(int i, int j) {
    vis[i][j] = 1;
    int ni, nj;
    tie(ni, nj) = getnext(i, j);
    if (!vis[ni][nj])
        dfs(ni, nj);
    nxt[i * m + j][0] = ni * m + nj;
}

void solve() {
    cin >> n >> m;
    nm = n * m;
    lognm = 0;
    while ((1 << lognm) <= nm)
        ++lognm;
    color = moves = vector<string>(n);
    for (int i = 0; i < n; i++)
        cin >> color[i];
    for (int i = 0; i < n; i++)
        cin >> moves[i];
    vis = vector<vector<bool>>(n, vector<bool>(m));
    nxt = vector<vector<int>>(nm, vector<int>(lognm));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j])
                dfs(i, j);
        }
    }
    for (int deg = 1; deg < lognm; deg++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int id = i * m + j;
                nxt[id][deg] = nxt[nxt[id][deg - 1]][deg - 1];
            }
        }
    }
    vector<vector<int>> black, white;
    black = white = vector<vector<int>>(n, vector<int>(m));
    for (int from = 0; from < nm; from++) {
        int to = from;
        for (int deg = lognm - 1; deg > 0; deg--) {
            if ((nm >> deg) & 1)
                to = nxt[to][deg];
        }
        if (color[from / m][from % m] == '0')
            black[to / m][to % m]++;
        else
            white[to / m][to % m]++;
    }
    int all = 0, blk = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (black[i][j])
                all++, blk++;
            else if (white[i][j])
                all++;
        }
    }
    cout << all << " " << blk << '\n';
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