#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> g;
    dsu(int n) : g(n, -1) {};
    int get(int u) {
        if (g[u] < 0) return u;
        else return g[u] = get(g[u]);
    }
    void uni(int u, int v) {
        u = get(u);
        v = get(v);
        if (u != v) {
            if (g[u] > g[v]) swap(u, v);
            g[u] += g[v];
            g[v] = u;
        }
    }
    int size(int u) {
        return -g[get(u)];
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> moves(k);
    vector<int> pos(n);
    vector<int> ans(n);
    iota(pos.begin(), pos.end(), 0);
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        swap(pos[a], pos[b]);
        moves[i] = make_pair(a, b);
    }
    dsu g(n);
    for (int i = 0; i < n; i++) {
        if (pos[i] != i) {
            g.uni(pos[i], i);
        }
    }
    vector<set<int>> at(n);
    iota(pos.begin(), pos.end(), 0);
    for (int i = 0; i < n; i++)
        at[g.get(i)].insert(i);
    for (int i = 0, a, b; i < k; i++) {
        tie(a, b) = moves[i];
        at[g.get(pos[a])].insert(b);
        at[g.get(pos[b])].insert(a);
        swap(pos[a], pos[b]);
    }
    for (int i = 0; i < n; i++) {
        cout << at[g.get(i)].size() << '\n';
    }
}

