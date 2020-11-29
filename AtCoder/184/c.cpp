#include <bits/stdc++.h>
using namespace std;

int check(int a, int b, int c, int d) {
    if (a == c && b == d) {
        return 0;
    } else if (a + b == c + d || a - b == c - d || abs(a - c) + abs(b - d) <= 3) {
        return 1;
    } else if ((a + b) % 2 == (c + d) % 2) {
        return 2;
    } else {
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                if (i != 0 || j != 0) {
                    int x = a + i, y = b + j;
                    if (x + y == c + d || x - y == c - d || abs(x - c) + abs(y - d) <= 3) {
                        return 2;
                    }
                }
            }
        }
        for (int i : {0, 3}) for (int j : {0, 3}) {
            if (i != 0 || j != 0) {
                int x = a + i, y = b + j;
                if (x + y == c + d || x - y == c - d || abs(x - c) + abs(y - d) <= 3) {
                    return 2;
                }
            }
        }
    }
    return 3;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << check(a, b, c, d) << '\n';
    return 0;
}