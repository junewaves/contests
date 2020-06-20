#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> odd, even;
    for (int i = 0, t; i < n * 2; i++) {
        cin >> t;
        if (t & 1)
            odd.emplace_back(t, i + 1);
        else
            even.emplace_back(t, i + 1);
    }
    int i = 0, j = 0;
    if (odd.size() & 1) 
        i++, j++;
    else {
        if ((int)odd.size() > 0)
            i += 2;
        else
            j += 2;
    }
    while (i < (int)odd.size()) {
        cout << odd[i].second << " " << odd[i + 1].second << "\n";
        i += 2;
    }
    while (j < (int)even.size()) {
        cout << even[j].second << " " << even[j + 1].second << "\n";
        j += 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}