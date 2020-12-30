#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> depth;
vector<array<int, 2>> dfs_time;
int global_dfs_time;
void dfs(int u, int p = -1, int d = 0) {
    depth[u] = d;
    dfs_time[u][0] = global_dfs_time++;
    for (int v : adj[u]) {
        if (v != p)
            dfs(v, u, d + 1);
    }
    dfs_time[u][1] = global_dfs_time++;
}

pair<int, int> query(const vector<int>& to_ask) {
    // print query
    cout << "? " << to_ask.size() << " ";
    for (int i : to_ask)
        cout << i << " ";
    cout << endl;
    // get response
    int n, d;
    cin >> n >> d;
    assert(n != -1 && d != -1);
    return { n, d };
}

bool is_anc(int p, int v) {
    return (dfs_time[p][0] <= dfs_time[v][0] &&
            dfs_time[v][1] <= dfs_time[p][1]);
}

void solve() {
    int n;
    cin >> n;
    adj = vector<vector<int>>(n);
    depth = vector<int>(n);
    dfs_time = vector<array<int, 2>>(n);
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // first query will find one of the node between hidden nodes
    vector<int> ask(n);
    int root, d_sum;
    for (int i = 1; i <= n; i++)
        ask[i - 1] = i;
    tie(root, d_sum) = query(ask);

    global_dfs_time = 0;
    dfs(root - 1);
    // set lower bound as ceil(d_sum / 2) can reduce 1 query
    int lo = (d_sum + 1) / 2, hi = d_sum, n1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int node, dist;
        ask.clear();
        for (int i = 0; i < n; i++) {
            if (depth[i] == mid)
                ask.push_back(i + 1);
        }
        if (ask.empty()) {
            hi = mid - 1;
            continue;
        }
        tie(node, dist) = query(ask);
        if (dist > d_sum) {
            hi = mid - 1;
        } else {
            n1 = node;
            lo = mid + 1;
        }
    }
    ask.clear();
    int n2, d2;
    if (depth[n1 - 1] == d_sum) {
        n2 = root;
    } else {
        for (int i = 0; i < n; i++) {
            if (depth[i] + depth[n1 - 1] == d_sum && !is_anc(i, n1 - 1))
                ask.push_back(i + 1);
        }
        if (ask.size() == 1)
            n2 = ask[0];
        else
            tie(n2, d2) = query(ask);  // get 2nd node
    }
    // print answer
    cout << "! " << n1 << " " << n2 << endl;
    string res;
    cin >> res;
    assert(res[0] == 'C');
    adj.clear();
    depth.clear();
    dfs_time.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}