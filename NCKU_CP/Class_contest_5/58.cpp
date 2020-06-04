#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge {
    int u, v, c;
    edge(int a, int b, int w) : u(a), v(b), c(w) {}
};
vector<int> group;
int Find(int u) {
    if (u == group[u])
        return u;
    return group[u] = Find(group[u]);
}
void Union(int u, int v) {
    int gu = Find(u), gv = Find(v);
    group[gu] = gv;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v, c;
    cin >> n >> m;
    group = vector<int>(n);
    for (int i = 0; i < n; i++)
        group[i] = i;

    vector<edge> E;
    E.reserve(m);
    int sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        E.emplace_back(--u, --v, c);
        sum += c;
    }
    sort(E.begin(), E.end(),
         [](const edge& x, const edge& y) { return x.c > y.c; });
    int w = 0, cnt = 0;
    for (int i = 0; i < m && cnt < n - 1; i++) {
        auto& e = E[i];
        int a = Find(e.u), b = Find(e.v);
        if (a != b) {
            Union(e.u, e.v);
            w += e.c;
            cnt++;
        }
    }
    cout << sum - w << '\n';
    return 0;
}
