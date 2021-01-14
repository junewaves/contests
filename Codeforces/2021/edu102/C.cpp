#include <bits/stdc++.h>
using namespace std;

int tt, n, k, a[100000];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> tt;
    while (tt--) {
        cin >> n >> k;
        iota(a, a + k, 1);
        reverse(a + k * 2 - n - 1, a + k);
        for (int i = 0; i < k; i++)
            cout << a[i] << " \n"[i == k - 1];
    }
    return 0;
}

