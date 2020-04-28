#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, best_monster = 0;
    vector<int> monsters;
    vector<pair<int, int>> players;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        monsters.push_back(tmp);
        best_monster = max(best_monster, tmp);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int p, s;
        cin >> p >> s;
        players.emplace_back(p, s);
    }
    sort(players.begin(), players.end(), greater<pair<int, int>>());
    if (best_monster > players[0].first) {
        cout << -1 << endl;
        exit(0);
    }
    int days = 0, killed = 0;
    while (killed < n) {
        int max_kill = 0;
        for (int i = 0; i < m; i++) {
            int j = killed, s = players[i].second;
            while (s > 0 && j < n && monsters[j] <= players[i].first)
                j++, s--;
            max_kill = max(max_kill, j);
        }
        killed = max_kill;
        days++;
    }
    cout << days << endl;
}
