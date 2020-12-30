#include <atcoder/dsu>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> m >> n;
    vector<int> a(m), b(n);
    for (int &it : a)
        cin >> it;
    for (int &it : b)
        cin >> it;
    vector<array<int, 3>> edges;
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            --x;
            edges.push_back({a[i] + b[x], n + i, x});
        }
    }
    sort(edges.rbegin(), edges.rend());
    atcoder::dsu D(m + n);
    int64_t cost = 0;   
    for (auto& e : edges) {
        if (D.same(e[1], e[2]))
            cost += e[0];
        else
            D.merge(e[1], e[2]);
    }
    cout << cost <<'\n';
    return 0;
}