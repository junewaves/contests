#include <bits/stdc++.h>
#ifndef _LOCAL_DEBUG
#define endl '\n'
#endif
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    int l = 2, r = n;
    while (l < r) {
        int mid = (l + r) / 2, covered = 0, used = 0;
        for (int i = 0; i < m; i++) {
            if (a[i] > covered) {
                covered = a[i] + mid - 2;
                if (++used > k)
                    break;
            }
        }
        if (used > k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
}