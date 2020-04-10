#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
typedef long long int ll;
ll l[100000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, sum = 0;
    bool flag = false;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> l[i];
        if (l[i] > n - i)
            flag = true;
        sum += l[i];
    }
    if (sum < n || flag) {
        cout << -1 << endl;
    } else {
        ll overlap = sum - n, pos = 1;
        for (int i = 0; i < m; i++) {
            cout << pos << " ";
            if (overlap > 0) {
                ll k = min(l[i] - 1, overlap);
                overlap -= k;
                pos += (l[i] - k);
            } else {
                pos += l[i];
            }
        }
        cout << endl;
    }
    return 0;
}