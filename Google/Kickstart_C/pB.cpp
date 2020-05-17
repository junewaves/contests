#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
void solve() {
    int r, c;
    cin >> r >> c;
    unordered_map<char, pair<int, unordered_set<char>>> graph;
    string s1, s2;
    cin >> s1;
    for (int i = 1; i < r; i++) {
        cin >> s2;
        for (int j = 0; j < c; j++) {
            char a = s1[j], b = s2[j];
            if (a != b && !graph[b].second.count(a)) {
                graph[b].second.insert(a);
                graph[a].first++;
            }
        }
        s1 = s2;
    }
    queue<char> q;
    string ans;
    for (const auto& p : graph) {
        if (p.second.first == 0) {
            q.push(p.first);
            ans += p.first;
        }
    }
    while (!q.empty()) {
        char u = q.front();
        q.pop();
        for (char v : graph[u].second) {
            if (--graph[v].first == 0) {
                q.push(v);
                ans += v;
            }
        }
    }
    cout << (ans.size() == graph.size() ? ans : "-1") << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    for (int i = 1; i <= _n; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
