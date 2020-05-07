#include <bits/stdc++.h>
#ifndef _LOCAL_DEBUG
#define endl '\n'
#endif
using namespace std;
int n, k, s[26];
char c;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> c;
        s[c - 'A']++;
    }
    int a = 1000000;
    for (int i = 0; i < k; i++)
        a = min(a, s[i]);
    cout << a * k << endl;
    return 0;
}
