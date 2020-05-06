#include <bits/stdc++.h>
#ifndef _LOCAL_DEBUG
#define endl '\n'
#endif
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> s(2, vector<int>(n + 1));
    int d = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                s[1][j] = s[0][j - 1] + 1;
            } else {
                s[1][j] = max(s[0][j], s[1][j - 1]);
            }
        }
        for (int j = 0; j <= n; j++) {
            s[0][j] = s[1][j];
            s[1][j] = 0;
        }
    }
    cout << s[0][n] << endl;
    return 0;
}
