#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    bool ok = false;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cnt++;
            if (cnt >= 3)
                ok = true;
        } else {
            cnt = 0;
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
    return 0;
}