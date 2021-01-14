#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (int &it : a) cin >> it;
        sort(a.begin(), a.end());
        if (a[n - 1] <= d || a[0] + a[1] <= d)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
