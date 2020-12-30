#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
ll n;
void solve() {
    cin >> n;
    vector<vector<ll>> monster(n, vector<ll>(2));
    for (int i = 0; i < n; i++) {
        cin >> monster[i][0] >> monster[i][1];
    }
    ll min_bullets = LONG_LONG_MAX;
    vector<int> best;
    for (int i = 0; i < n; i++) {
        ll bullets_used = monster[i][0], dmg = monster[i][1];
        for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
            if (dmg < monster[j][0]) {
                bullets_used += monster[j][0] - dmg;
            }
            dmg = monster[j][1];
        }
        if (min_bullets > bullets_used) {
            min_bullets = bullets_used;
            best.resize(1);
            best[0] = i;
        } else if (min_bullets == bullets_used) {
            best.push_back(i);
        }
    }
    cout << min_bullets << endl;
    for (int i : best)
        cout << i << " ";
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
    return 0;
}