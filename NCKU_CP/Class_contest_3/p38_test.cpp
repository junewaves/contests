#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, best = 0;
    vector<int> monsters;
    vector<pair<int, int>> players;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        monsters.push_back(tmp);
        best = max(best, tmp);
    }
    cin >> m;
    bool possible = false;
    for (int i = 0; i < m; i++) {
        int p, s;
        cin >> p >> s;
        if (p > best)
            possible = true;
        players.emplace_back(p, s);
    }
    if (!possible) {
        cout << -1 << endl;
        exit(0);
    }
    int a = 0, days = 0;
    while (a < n) {
        int max_kill = 0;
        for (int i = 0; i < m; i++) {
            int j = a, s = players[i].second;
            while (s && j < n && players[i].first >= monsters[j]) {
                j++, s--;
            }
            max_kill = max(max_kill, j);
        }
        a = max_kill;
        days++;
    }
    cout << days << endl;
}
