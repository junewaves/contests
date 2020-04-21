// Codeforces Round #636 (Div. 3) (4/21)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
vector<vector<int>> edges;
int n, m, a, b, c;
void bfs(int s, int t, vector<int>& d) {
    d.assign(n, -1);
    queue<int> q;
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i : edges[u]) {
            if (d[i] != -1)
                continue;
            d[i] = d[u] + 1;
            if (i == t)
                return;
            q.push(i);
        }
    }
}
void solve() {
    cin >> n >> m >> a >> b >> c;
    a--, b--, c--;
    edges.resize(n);
    edges.assign(n, vector<int>());
    vector<int> weights(m);
    for (int i = 0; i < m; i++)
        cin >> weights[i];
    sort(weights.begin(), weights.end());
    for (int i = 0; i < m; i++) {
        int d, e;
        cin >> d >> e;
        edges[d - 1].push_back(e - 1);
        edges[e - 1].push_back(d - 1);
    }
    vector<int> da, db;
    bfs(a, b, da);
    bfs(b, c, db);
    for (int i : da)
        cout << i << " ";
    cout << endl;
    for (int i : db)
        cout << i << " ";
    cout << endl;
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
