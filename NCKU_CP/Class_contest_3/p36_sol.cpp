#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
int stick[1001];
ll dp[1000][1001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        stick[i] = stick[i - 1] + t;
    }
    for (int len = 2; len <= n; len++) {
        for (int s = 0; s + len <= n; s++) {
            dp[s][s + len] = INF;
            for (int i = s + 1; i < s + len; i++) {
                dp[s][s + len] = min(dp[s][s + len], dp[s][i] + dp[i][s + len]);
            }
            dp[s][s + len] += stick[s + len] - stick[s];
        }
    }
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[0][n] << '\n';
}
