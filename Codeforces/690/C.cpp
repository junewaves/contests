#include <bits/stdc++.h>
using namespace std;

int ans[51];
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int x = 1;
    for (int i = 0, p = 1; i < 9; i++, p *= 10) {
        int suf = 0;
        for (int j = 10 - i; j <= 9; j++)
            suf = suf * 10 + j;
        for (int k = 1; k < 10 - i; k++)
            ans[x++] = k * p + suf;
    }
    while (x <= 50) ans[x++] = -1;
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }
    return 0;
}