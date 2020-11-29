#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    const char* P1 = "Ashish";
    const char* P2 = "Utkarsh";
    int tt;
    cin >> tt;
    while (tt--) {
        int d, k;
        cin >> d >> k;
        int64_t mx = 1LL * d * d;
        int64_t x = 0, y = 0;
        int turn = 1;
        while (x * x + y * y <= mx) {
            if (turn & 1)
                x += k;
            else
                y += k;
            turn++;
        }
        cout << (turn % 2 ? P1 : P2) << '\n';
    }
    return 0;
}