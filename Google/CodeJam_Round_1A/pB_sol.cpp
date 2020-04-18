// Code Jam Round 1A (4/11)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
int _n, N;
void solve() {
    cin >> N;
    if (N <= 30) {
        for (int i = 1; i <= N; i++)
            cout << i << " " << 1 << endl;
        return;
    }
    int tar, tmp, zeros, i = 30;
    tmp = tar = N - i;
    zeros = 0;
    while (tmp > 0) {
        if ((tmp & 1) == 0)
            zeros++;
        tmp >>= 1;
    }
    i -= zeros;

    bool left = true;
    int r = 1;
    while (tar > 0) {
        if (tar & 1) {
            for (int j = 0; j < r; j++) {
                cout << r << " " << (left ? j + 1 : r - j) << endl;
            }
            left = !left;
        } else {
            cout << r << " " << (left ? 1 : r) << endl;
        }
        tar >>= 1;
        r++;
    }
    for (int j = 0; j < i; j++, r++) {
        cout << r << " " << (left ? 1 : r) << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _n;
    for (int _cn = 1; _cn <= _n; _cn++) {
        cout << "Case #" << _cn << ": \n";
        solve();
    }
    return 0;
}