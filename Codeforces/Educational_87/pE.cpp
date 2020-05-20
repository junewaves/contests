#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, n1, n2, n3;
bool bad;
vector<int> color;
vector<bool> vis;
vector<vector<int>> adj;
void dfs(int u, int set_color, array<int, 2>& cnt) {
    color[u] = set_color;  // set_color = 1, 2
    cnt[set_color - 1]++;
    for (int i : adj[u]) {
        if (color[i] == 0) {
            dfs(i, set_color ^ 3, cnt);
        } else if (color[i] == color[u]) {
            bad = true;
            return;
        }
    }
}
void flip_color(int u) {
    vis[u] = true;
    color[u] ^= 3;
    for (int i : adj[u]) {
        if (!vis[i])
            flip_color(i);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> n1 >> n2 >> n3;
    color.resize(n, 0);
    vis.resize(n, false);
    adj.resize(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bad = false;
    vector<array<int, 3>> con;  // imformation of connected components
    for (int i = 0; i < n && !bad; i++) {
        if (color[i] == 0) {
            array<int, 2> tmp = { 0, 0 };
            dfs(i, 1, tmp);
            con.push_back({ i, tmp[0], tmp[1] });
            // con[i] = {head node id, # of color1, # of color2}
        }
    }
    if (bad) {
        cout << "NO\n";
        return 0;
    }
    int con_s = con.size();  // # of connected components
    vector<vector<int>> dp(con_s + 1, vector<int>(n2 + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < con_s; i++) {
        for (int j = 0; j <= n2; j++) {
            if (dp[i][j]) {
                if (j + con[i][1] <= n2)
                    dp[i + 1][j + con[i][1]] = 1;
                if (j + con[i][2] <= n2)
                    dp[i + 1][j + con[i][2]] = 2;
            }
        }
    }
    if (!dp[con_s][n2]) {
        cout << "NO\n";
        return 0;
    }
    for (int i = con_s; i > 0; i--) {
        int use_color = dp[i][n2];
        if (use_color == 1)
            flip_color(con[i - 1][0]);
        n2 -= con[i - 1][use_color];
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        if (color[i] == 1) {
            if (n1)
                --n1;
            else
                color[i] = 3;
        }
        cout << color[i];
    }
    cout << '\n';
}
