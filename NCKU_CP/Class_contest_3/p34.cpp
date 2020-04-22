#include <bits/stdc++.h>
using namespace std;
#ifndef _LOCAL_DEBUG
#define endl '\n'
#endif
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n <= 9) {
        cout << n << endl;
        return 0;
    }
    vector<int> dec(4, 0);
    while (1) {
        if (n % 2)
            break;
        else {
            n /= 2;
            dec[0]++;
        }
    }
    while (1) {
        if (n % 3)
            break;
        else {
            n /= 3;
            dec[1]++;
        }
    }
    while (1) {
        if (n % 5)
            break;
        else {
            n /= 5;
            dec[2]++;
        }
    }
    while (1) {
        if (n % 7)
            break;
        else {
            n /= 7;
            dec[3]++;
        }
    }
    if (!dec[0] && !dec[1] && !dec[2] && !dec[3]) {
        cout << "-1" << endl;
        return 0;
    }
    if (n > 1) {
        cout << "-1" << endl;
        return 0;
    }

    vector<int> a(10, 0);
    // 8
    if (dec[0] >= 3) {
        a[8] = dec[0] / 3;
        dec[0] %= 3;
    }

    // 4
    if (dec[0] == 2) {
        a[4] = dec[0] == 2 ? 1 : 0;
        dec[0] %= 2;
    }
    // 9
    if (dec[1] >= 2) {
        a[9] = dec[1] / 2;
        dec[1] %= 2;
    }
    // 6
    if (dec[0] > 0 && dec[1] > 0) {
        a[6] = min(dec[0], dec[1]);
        dec[0] -= a[6];
        dec[1] -= a[6];
    }
    a[2] = dec[0];
    a[3] = dec[1];
    a[5] = dec[2];
    a[7] = dec[3];
    // print
    for (int i = 2; i <= 9; i++) {
        for (int j = 0; j < a[i]; j++) {
            cout << i;
        }
    }
    cout << endl;
    return 0;
}