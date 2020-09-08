#include <bits/stdc++.h>
using namespace std;

int n;
int query(int i, int j) {
    int ret;
    cout << "? " << i << " " << j << endl;
    cin >> ret;
    assert(0 <= ret && ret <= n - 1);
    return ret;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    vector<int> ans(n, -1);
    int x = 1, y = 2, a, b;
    for (int i = 0; i < n - 1; i++) {
        a = query(x, y);
        b = query(y, x);
        if (a > b) {
            ans[x - 1] = a;
            x = y;
            y++;
        } else {
            ans[y - 1] = b;
            y++;
        }
    }
    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << (ans[i] == -1 ? n : ans[i]) << ' ';
    }
    cout << endl;
    return 0;
}