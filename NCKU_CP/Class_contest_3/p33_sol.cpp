#include <iostream>
using namespace std;
int n, m, dp[100][100][100] = { 0 };
int main() {
    cin >> n >> m;
    // m: N 0 <-> 99 S
    // n: E 0 <-> 99 W
    dp[0][0][0] = 1;
    for (int x = 0; x < 100; x++) {
        if (x == 73)
            continue;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (x >= 2)
                    dp[x][i][j] += dp[x - 2][i][j];
                if (x >= 1 && j >= 1)
                    dp[x][i][j] += dp[x - 1][i][j - 1];
                if (i >= 1 && x < 99)
                    dp[x][i][j] += dp[x][i - 1][j];
                if (j >= 1 && x < 99)
                    dp[x][i][j] += dp[x][i][j - 1];
                dp[x][i][j] %= 48763;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum += dp[99][i][j];
        }
    }
    cout << sum % 48763 << '\n';
}