#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
typedef long long int ll;
int p[11] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    for (int i = 0; i < 11; i++) {
        if (n % p[i] == 0) {
            m = n / p[i];
            cout << p[i] << m << endl;
            break;
        }
    }
}