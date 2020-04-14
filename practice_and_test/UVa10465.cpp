// UVa 10465 - Homer Simpson
#include <bits/stdc++.h>
using namespace std;
#ifndef _LOCAL_DEBUG
#define endl '\n'
#endif
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, t;
    while (cin >> n >> m >> t) {
        vector<int> S(t + 1, -1);
        S[0] = 0;
        for (int i = n; i <= t; i++)
            if (S[i - n] != -1)
                S[i] = max(S[i], S[i - n] + 1);
        for (int i = m; i <= t; i++)
            if (S[i - m] != -1)
                S[i] = max(S[i], S[i - m] + 1);
        for (int i = t; i >= 0; i--) {
            if (S[i] > -1) {
                cout << S[i];
                if (i < t)
                    cout << " " << t - i;
                cout << endl;
                break;
            }
        }
    }
}
