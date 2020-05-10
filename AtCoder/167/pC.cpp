#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x;
    vector<vector<int>> c(n, vector<int>(m));
    vector<int> ml(m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
            ml[j] += c[i][j];
        }
    for (int l : ml) {
        if (l < x) {
            cout << "-1";
            return 0;
        }
    }
}
