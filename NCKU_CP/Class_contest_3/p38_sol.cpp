#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    vector<int> mo(n + 1), pl(n + 1);
    for (int i = 0; i < n; i++)
        cin >> mo[i];  // i-th monster's power
    cin >> m;
    for (int i = 0; i < m; i++) {
        int p, s;
        cin >> p >> s;
        pl[s] = max(pl[s], p);
    }
    for (int s = n - 1; s >= 1; s--)
        pl[s] = max(pl[s], pl[s + 1]);
    // pl: max power of the player that can kill s monsters in one day
    int k = 0, days = 0;
    while (k < n) {
        int s = 1;
        int mon_s = mo[k];  // strongest monster from k to k + s - 1
        while (k < n && mon_s <= pl[s]) {
            mon_s = max(mon_s, mo[++k]);
            s++;
        }
        if (s == 1)  // can't kill any monster
            break;
        days++;
    }
    if (k == n)
        cout << days << '\n';
    else
        cout << "-1\n";
}
