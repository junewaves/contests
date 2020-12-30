#include <bits/stdc++.h>
using namespace std;

#ifdef _LOCAL_DEBUG
#define en_if typename enable_if<sizeof x<T>(0) == 4, ostream&>::type
namespace dbg {
template<class T> char x(...); 
template<class T> auto x(T* v) -> decltype(v->size(), 0); 
template<class T> auto x(T* v) -> decltype(v->c_str(), "");
template<class T> en_if operator<<(ostream& os, const T& v) { 
    os << "["; const char* sep = ""; 
    for(const auto& x : v) os << sep << x, sep = ", ";
    return os << "]";
}
template<class F, class S> 
ostream& operator<<(ostream& os, const pair<F, S>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template<class T> 
void print(const char* n, T e) { cerr << "[" << n << ": " << e << "]\n"; }
template<class Head, class... Tail> 
void print(const char* n, Head h, Tail... t) {
    cerr << "["; while(*n != ',') cerr << *n++; cerr << ": " << h << "] ";
    print(n + 2, t...); 
}}
#define debug(...) dbg::print(#__VA_ARGS__, __VA_ARGS__);
#else
#define debug(...)
#endif

void solve() {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    --a, --b;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    debug(adj);
    vector<bool> vis(n);
    vector<int> dis(n);
    vis[a] = true;
    queue<int> q;
    q.push(a);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    int dis_b = dis[b];
    int root = max_element(dis.begin(), dis.end()) - dis.begin();
    fill(vis.begin(), vis.end(), false);
    fill(dis.begin(), dis.end(), 0);
    vis[root] = true;
    q.push(root);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    int diameter = *max_element(dis.begin(), dis.end());
    if (dis_b <= da || db < da * 2 + 1 || diameter < da * 2 + 1) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}