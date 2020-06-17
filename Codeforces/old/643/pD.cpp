#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    if (s >= n * 2) {
        cout << "YES\n";
        for (int i = 0; i < n - 1; i++) {
            cout << 1 << " ";
        }
        cout << s - n + 1 << endl;
        cout << n << endl;
    } else {
        cout << "NO\n";
    }
    return 0;
}
