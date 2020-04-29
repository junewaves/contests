#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    unordered_set<int> sp(k);
    vector<vector<int>> edges(n);
    bool sp_connected = false;
    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        sp.insert(t - 1);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
        if (!sp_connected && sp.count(a - 1) && sp.count(b - 1))
            sp_connected = true;
    }
    vector<int> distance(n, -1);
    distance[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int i = q.front(), d = distance[i];
        q.pop();
        for (int j : edges[i]) {
            if (distance[j] == -1) {
                distance[j] = d + 1;
                q.push(j);
            }
        }
    }
    if (sp_connected) {
        cout << distance[n - 1] << endl;
    } else {
        int max_distance = 0;
        for (int i = 0; i < n - 1; i++) {
            if (sp.count(i) && distance[i] > max_distance) {
                max_distance = distance[i];
            }
        }
        if (max_distance >= distance[n - 1])
            cout << distance[n - 1] << endl;
        else
            cout << max_distance + 1 << endl;
    }
}