#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int mxN = 1e6 + 5;
/* sol 1: simulation with BIT
struct BIT {
    int s[mxN], size;
    void update(int i, int d) {
        for (; i <= size; i += i & -i) {
            s[i] += d;
        }
    }
    int get(int i) {
        if (i == 0)
            return 0;
        int a = 0;
        for (; i; i -= i & -i) {
            a += s[i];
        }
        return a;
    }
} tree;*/
vector<int> a, b;
int count(int x) {
    int cnt = 0;
    for (int i : a)
        if (i <= x)
            cnt++;
    for (int j : b) {
        if (j > 0 && j <= x)
            cnt++;
        else if (j < 0 && -j <= cnt)
            cnt--;
    }
    return cnt;
}
void solve() {
    int n, q;
    cin >> n >> q;
    /* sol 1: simulation with BIT
    tree.size = n;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        tree.update(t, 1);
    }
    for (int i = 0; i < q; i++) {
        cin >> t;
        if (t > 0) {
            tree.update(t, 1);
        } else {
            t = -t;
            int l = 1, r = n;
            while (l < r) {
                int m = (l + r) / 2;
                if (tree.get(m) < t)
                    l = m + 1;
                else
                    r = m;
            }
            tree.update(l, -1);
        }
    }
    for (int i = 0; i <= n; i++) {
        // cout << s[i] << " ";
        if (tree.s[i]) {
            cout << i << "\n";
            return;
        }
    }
    cout << "0\n";
*/
    a.resize(n);
    b.resize(q);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> b[i];
    }
    int l = 1, r = mxN;
    while (l < r) {
        int m = (l + r) / 2;
        if (count(m) > 0)
            r = m;
        else
            l = m + 1;
    }
    cout << (r == mxN ? 0 : r) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
