#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = 2e5 + 1;
int n, m, l, r, group[MAX_N], gmax[MAX_N];
int Find(int v) {
    if (v == group[v])
        return v;
    else
        return group[v] = Find(group[v]);
}
void Union(int u, int v) {
    int gu = Find(u), gv = Find(v);
    if (gu > gv) {
        group[gu] = gv;
        gmax[gv] = max(gmax[gu], gmax[gv]);
    } else {
        group[gv] = gu;
        gmax[gu] = max(gmax[gu], gmax[gv]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    // initialize group
    for (int i = 1; i <= n; i++) {
        group[i] = gmax[i] = i;
    }
    // get input edges
    while (m--) {
        cin >> l >> r;
        Union(l, r);
    }
    int new_edges = 0;
    for (int l = 1, m; l <= n; l = m) {
        for (m = l + 1; m <= gmax[Find(l)]; m++) {
            if (Find(l) == Find(m))
                continue;
            Union(l, m);
            new_edges++;
        }
    }
    cout << new_edges << '\n';
}