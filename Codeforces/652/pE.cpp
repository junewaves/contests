#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> has(n);
    vector<set<int>> who(n);
    vector<array<int, 2>> likes(m);
    for (int& it : has)
        cin >> it;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        who[a].insert(i);
        who[b].insert(i);
        likes[i][0] = a;
        likes[i][1] = b;
    }
    queue<int> q;
    vector<int> ans;
    vector<bool> used(n);
    for (int i = 0; i < n; i++) {
        if ((int)who[i].size() <= has[i])
            q.push(i), used[i] = true;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int p : who[u]) {
            int v = (likes[p][0] ^ likes[p][1]) ^ u;
            who[v].erase(p);
            ans.push_back(p);
            if (!used[v] && (int)who[v].size() <= has[v])
                q.push(v), used[v] = true;
        }
    }
    if ((int)ans.size() != m) {
        cout << "DEAD\n";
    } else {
        cout << "ALIVE\n";
        for (int i = m - 1; i >= 0; i--)
            cout << ans[i] + 1 << " \n"[!i];
    }
    return 0;
}