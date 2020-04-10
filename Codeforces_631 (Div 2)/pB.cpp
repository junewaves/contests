#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
typedef long long int ll;
int a[200001];
bool b[200001];
bool is_permutation(int s, int e) {
    memset(b, 0, sizeof(b));
    for (int i = s; i < e; i++) {
        b[a[i]] = true;
    }
    for (int i = 1; i <= e - s; i++) {
        if (b[i] == false)
            return false;
    }
    return true;
}
void solve() {
    memset(a, 0, sizeof(a));
    int n, amax = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        amax = max(amax, a[i]);
    }
    if (amax < (n + 1) / 2) {
        cout << 0 << endl;
        return;
    }
    int diff = n - amax, cnt = 0;
    if (diff != n - diff) {
        int cd1 = is_permutation(0, diff) && is_permutation(diff, n),
            cd2 = is_permutation(0, n - diff) && is_permutation(n - diff, n);
        cout << cd1 + cd2 << endl;
        if (cd1)
            cout << diff << " " << n - diff << endl;
        if (cd2)
            cout << n - diff << " " << diff << endl;
    } else {
        int cd1 = is_permutation(0, diff) && is_permutation(diff, n);
        cout << cd1 << endl;
        if (cd1)
            cout << diff << " " << n - diff << endl;
    }
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