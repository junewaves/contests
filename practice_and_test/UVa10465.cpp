// UVa 10465 - Homer Simpson
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int n, m, t;
    while (cin >> n >> m >> t) {
        int N = max(0, (int)ceil(log2(t) - log2(n)) + 1);
        int M = max(0, (int)ceil(log2(t) - log2(m)) + 1);
        vector<vector<int>> S(M + N + 1, vector<int>(t + 1, 0));
        vector<int> V(M + N + 1), P(M + N + 1);
        int C = 1;
        for (int i = 0; m * pow(2, i) <= t; i++) {
            V[C] = m * pow(2, i);
            P[C] = pow(2, i);
            C++;
        }
        for (int i = 0; n * pow(2, i) <= t; i++) {
            V[C] = n * pow(2, i);
            P[C] = pow(2, i);
            C++;
        }
        for (int i = 0; i < C; i++) {
            for (int j = 0; j <= t; j++) {
                S[i][j] = (j == 0 ? 0 : -1);
            }
        }
        for (int i = 1; i < C; i++) {
            for (int j = 0; j <= t; j++) {
                if (j >= V[i] && S[i - 1][j - V[i]] != -1)
                    S[i][j] = max(S[i - 1][j], S[i - 1][j - V[i]] + P[i]);
                else
                    S[i][j] = S[i - 1][j];
            }
        }
        for (int i = t; i >= 0; i--) {
            if (S[C - 1][i] > -1) {
                cout << S[C - 1][i];
                if (i < t)
                    cout << " " << t - i;
                cout << '\n';
                break;
            }
        }
    }
}
