#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), l(n);
    for (int& it : a) cin >> it;
    for (int& it : l) cin >> it;
    vector<int> unlocked;
    for (int i = 0; i < n; i++)
        if (l[i] == 0)
            unlocked.push_back(a[i]);
    sort(unlocked.rbegin(), unlocked.rend());
    for (int i = 0, j = 0; i < n; i++) {
        if (l[i] == 0)
            cout << unlocked[j++];
        else
            cout << a[i];
        cout << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}