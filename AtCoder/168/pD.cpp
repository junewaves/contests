#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ad[100001];
int p[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    // vector<vector<int>> ad(n, vector<int>());
    // vector<int> d(n, 0x3f3f3f3f);
    memset(p, -1, sizeof(p));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // int val = d[u] + 1;
        for (int v : ad[u]) {
            if (p[v] == -1) {
                p[v] = u;
                q.push(v);
            }
        }
    }
    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (p[i] == -1) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << "Yes\n";
        for (int i = 1; i < n; i++)
            cout << p[i] + 1 << '\n';
    } else {
        cout << "No\n";
    }
}
