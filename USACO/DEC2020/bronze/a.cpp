#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int a[7];
    for (int i = 0; i < 7; i++)
        cin >> a[i];
    sort(a, a + 7);
    do {
        if (a[0] + a[1] + a[2] == a[6] && a[3] + a[4] + a[5] == a[6] * 2) {
            sort(a, a + 3);
            cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
            return 0;
        }
    } while (next_permutation(a, a + 6));
    return 0;
}