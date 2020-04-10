#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

ll n, monster[300000][2];
int pos[300000];
void solve() {
    cin >> n;
    memset(monster, 0, sizeof(monster));
    for (int i = 0; i < n; i++) {
        cin >> monster[i][0] >> monster[i][1];
        pos[i] = i;
    }
    ll min_bullets = LONG_LONG_MAX;
    int t0 = 0;
    for (int i = 0; i < n; i++) {
        ll bullets_used = monster[i][0], dmg = monster[i][1];
        ll total_dmg = 0, b = monster[i][0];
        for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
            if (dmg < monster[j][0]) {
                bullets_used += monster[j][0] - dmg;
                // total_dmg += dmg;
                // break;
            }
            total_dmg += monster[j][0];
            dmg = monster[j][1];
        }
        // cout << i << ": " << bullets_used << ", " << total_dmg << ", " << b
        //      << endl;
        if (min_bullets > bullets_used) {
            min_bullets = bullets_used;
            t0 = i;
        }
    }
    cout << min_bullets << ", " << t0 << endl;
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