#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
typedef long long int ll;
void solve() {
    int n;
    cin >> n;
    vector<int> m(n * n);
    unordered_set<int> seen;
    int d = 0, r = n - 1, trace = 0, rcount = 0;
    bool repeat_flag = false;
    for (int i = 0; i < n * n; i++) {
        cin >> m[i];
        if (!repeat_flag && seen.count(m[i]) == 0) {
            seen.insert(m[i]);
        } else {
            repeat_flag = true;
        }
        if (i == d) {
            trace += m[i];
            d += (n + 1);
        }
        if (i == r) {
            rcount += (int)repeat_flag;
            repeat_flag = false;
            seen.clear();
            r += n;
        }
    }
    int ccount = 0;
    for (int i = 0; i < n; i++) {
        repeat_flag = false;
        seen.clear();
        for (int j = i; j < n * n; j += n) {
            if (!repeat_flag && seen.count(m[j]) == 0) {
                seen.insert(m[j]);
            } else {
                repeat_flag = true;
            }
        }
        ccount += (int)repeat_flag;
    }
    cout << trace << " " << rcount << " " << ccount << endl;
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