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
        int l = 0, r = n - 1;
        while (l < r) {
            cout << a[l++] << ' ';
            cout << a[r--] << ' ';
        }
        if (l == r) 
            cout << a[l] << '\n';
        else
            cout << '\n';
    }
    return 0;
}