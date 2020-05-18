#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
set<int> graph[26];
bool vis[26], use[26], bad;
string ans;
void dfs(int u) {
    vis[u] = true;
    use[u] = true;
    for (int v : graph[u]) {
        if (use[v]) {
            bad = true;
        } else if (!vis[v]) {
            dfs(v);
        }
    }
    use[u] = false;
    ans += (char)(u + 'A');
}
void solve() {
    int r, c;
    cin >> r >> c;
    // set<int> graph[26];
    set<int> seen;
    string s1, s2;
    cin >> s1;
    for (char a : s1)
        seen.insert(a - 'A');
    for (int i = 1; i < r; i++) {
        cin >> s2;
        for (int j = 0; j < c; j++) {
            int a = s1[j] - 'A', b = s2[j] - 'A';
            if (a != b && !graph[a].count(b)) {
                graph[a].insert(b);
                seen.insert(b);
            }
        }
        s1 = s2;
    }
    memset(vis, 0, 26);
    memset(use, 0, 26);
    bad = false;
    ans = "";
    for (int u : seen) {
        if (!vis[u])
            dfs(u);
    }
    if (bad)
        cout << "-1\n";
    else
        cout << ans << '\n';
    for (int i = 0; i < 26; i++) {
        graph[i].clear();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    for (int i = 1; i <= _n; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
