#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> pii;
vector<pair<int, long long>> graph[100005];
int n, e;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> e;
    int from, to, cost;
    for (int i = 0; i < e; i++) {
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
        graph[to].push_back(make_pair(from, cost));
    }
    // Djikstra's shorted path algorithm
    vector<long long> D(n, LONG_LONG_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> W;
    D[0] = 0;
    W.push(make_pair(0, 0));
    while (!W.empty()) {
        int now = W.top().second;
        long long d = W.top().first;
        W.pop();
        if (D[now] < d)
            continue;
        for (auto p : graph[now]) {
            long long alt = D[now] + p.second;
            if (alt < D[p.first]) {
                D[p.first] = alt;
                W.push(make_pair(D[p.first], p.first));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << D[i] << " \n"[i == n - 1];
    }

    return 0;
}
