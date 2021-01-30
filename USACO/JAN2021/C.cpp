#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int row = 0;
    for (int i = 0; i < n; i++) {
        int sum[2]{};
        for (int j = 0; j < n; j++)
            sum[j & 1] += a[i][j];
        row += max(sum[0], sum[1]);
    }
    int col = 0;
    for (int j = 0; j < n; j++) {
        int sum[2]{};
        for (int i = 0; i < n; i++)
            sum[i & 1] += a[i][j];
        col += max(sum[0], sum[1]);
    }
    cout << max(row, col) << '\n';
    return 0;
}
