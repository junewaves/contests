// Uva 10369 - Arctic Network (minimum spanning tree)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
const int mxN = 500;
typedef pair<double, double> point;
struct Edge {
    int u, v;  // u := start id, v := end id
    double w;  // w := weight(distance)
    Edge() : u(0), v(0), w(0.0) {}
    Edge(int a, int b, double c) : u(a), v(b), w(c) {}
    bool operator<(const Edge& rhs) const { return w < rhs.w; }
};
point co[mxN];
int group[mxN * mxN];
int Find(int u) {
    if (group[u] == u)
        return u;
    return group[u] = Find(group[u]);
}
void Union(int u, int v) {
    group[Find(u)] = Find(v);
}
double dist(const point& a, const point& b) {
    double dx = a.X - b.X, dy = a.Y - b.Y;
    return sqrt(dx * dx + dy * dy);
}
void solve() {
    int s, p;
    cin >> s >> p;
    vector<Edge> E;
    for (int v = 0; v < p; v++) {
        cin >> co[v].X >> co[v].Y;
        for (int u = 0; u < v; u++) {
            E.emplace_back(u, v, dist(co[u], co[v]));
        }
    }
    sort(E.begin(), E.end());
    for (int i = 0; i < p * p; i++)
        group[i] = i;
    vector<double> D;
    for (const Edge& e : E) {
        // cout << e.w << " ";
        int a = Find(e.u), b = Find(e.v);
        if (a != b) {
            D.push_back(e.w);
            Union(e.u, e.v);
        }
    }
    // cout << endl;
    cout << D[p - s - 1] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    cout << fixed << setprecision(2);
    while (T--) {
        solve();
    }
}
