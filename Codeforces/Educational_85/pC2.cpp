#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
ll n, monster[300000][2];
double r[300000];
void solve() {
    cin >> n;
    memset(monster, 0, sizeof(monster));
    double rmax = 0.0;
    ll pmax = 0;
    int ii1 = 0, ii2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> monster[i][0] >> monster[i][1];
        r[i] = (double)monster[i][1] / (double)monster[i][0];
        if (r[i] > rmax) {
            rmax = r[i];
            ii1 = i;
        }
        if (i > 0) {
            ll p = monster[i][0] - monster[i - 1][1];
            if (p > pmax) {
                pmax = p;
                ii2 = i;
            }
        }
    }
    ll p = monster[0][0] - monster[n - 1][1];
    if (p > pmax) {
        pmax = p;
        ii2 = 0;
    }
    ll min_b = LONG_LONG_MAX;
    for (int ii : { ii1, ii2 }) {
        ll bullets_used = monster[ii][0], dmg = monster[ii][1];
        for (int j = (ii + 1) % n; j != ii; j = (j + 1) % n) {
            if (dmg < monster[j][0]) {
                bullets_used += monster[j][0] - dmg;
            }
            dmg = monster[j][1];
        }
        min_b = min(min_b, bullets_used);
    }
    cout << min_b << endl;
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