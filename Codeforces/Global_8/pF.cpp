#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int add(int a, int b, int n) {
    // (a + b) % n
    a += b;
    while (a >= n)
        a -= n;
    while (a < 0)
        a += n;
    return a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    // find max k
    int mx = 0, k = -1;
    for (int i = 2; i <= n; i++) {
        int x = n - i - ((n + i - 1) / i) + 1;
        if (x > mx) {
            mx = x;
            k = i;
        }
    }
    if (k == -1) {
        cout << 0 << endl;
        return 0;
    }
    vector<bool> ok(n, true), on(n, false);
    for (int i = 0; i < n; i += k)
        ok[i] = false;
    vector<int> turnon;
    while (true) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ok[i] && !on[i]) {
                on[i] = true;
                turnon.push_back(i + 1);
                if (++cnt == k)
                    break;
            }
        }
        if (cnt < k)
            break;
        cout << k << ' ';
        for (int t : turnon)
            cout << t << ' ';
        cout << endl;
        int ret;
        cin >> ret, --ret;
        assert(ret >= 0);
        for (int i = 0; i < k; i++)
            on[add(ret, i, n)] = false;
        turnon.clear();
    }
    cout << 0 << endl;
    return 0;
}