#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &it : a) cin >> it;
        set<int> res;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res.insert(a[j] - a[i]);
            }
        }
        cout << res.size() << '\n';
    }
    return 0;
}