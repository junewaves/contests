#include <bits/stdc++.h>
using namespace std;

using ld = long double;
ld pr[101][101][101];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int A, B, C;
    cin >> A >> B >> C;
    pr[A][B][C] = 1.0;
    for (int a = A; a < 100; a++) {
        for (int b = B; b < 100; b++) {
            for (int c = C; c < 100; c++) {
                pr[a + 1][b][c] += pr[a][b][c] * a / ld(a + b + c);
                pr[a][b + 1][c] += pr[a][b][c] * b / ld(a + b + c);
                pr[a][b][c + 1] += pr[a][b][c] * c / ld(a + b + c);
            }
        }
    }
    ld ans = 0;
    for (int b = B; b < 100; b++)
        for (int c = C; c < 100; c++)
            ans += (100 - A + b - B + c - C) * pr[100][b][c];
    for (int a = A; a < 100; a++)
        for (int c = C; c < 100; c++)
            ans += (a - A + 100 - B + c - C) * pr[a][100][c];
    for (int a = A; a < 100; a++)
        for (int b = B; b < 100; b++)
            ans += (a - A + b - B + 100 - C) * pr[a][b][100];
    cout << fixed << setprecision(20) << ans;
    return 0;
}