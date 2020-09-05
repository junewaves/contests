#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int z = y - x;
        int d = 1;
        while (z % d != 0 || z / d + 1 > n) d++;
        int l = y - (n - 1) * d;
        if (l <= 0) l = l % d + d;
        int r = l + (n - 1) * d;
        for (int i = l; i <= r; i += d)
            cout << i << " \n"[i == r];
    }
    return 0;
}