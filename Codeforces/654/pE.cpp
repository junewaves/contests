#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int& v : a)
        cin >> v;
    sort(a.begin(), a.end());
    int b = a[0];
    for (int i = 1; i < n; i++) {
        b = max(b, a[i] - i);
    }
    int l = 0, r = 1e9 + 1;
    while (l < r) {
        int m = l + (r - l + 1) / 2;
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = max(0, a[i] - m);
        }
        int cnt = 0, mxp = 0, mark = c.back(), sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (c[i] != mark) {
                mxp = max({mxp, cnt, n - mark - sum});
                sum += cnt;
                cnt = 0;
                mark = c[i];
            }
            if (c[i] == 0) {
                mxp = max(mxp, i + 1);
                break;
            }
            cnt++;
        }
        if (mxp < p) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    if (l >= b) {
        cout << l - b + 1 << '\n';
        for (int i = b; i <= l; i++)
            cout << i << ' ';
        cout << '\n';
    } else {
        cout << "0\n";
    }
    return 0;
}