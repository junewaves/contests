#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<pair<int, int>> A(n);
        vector<int> L(n), R(n);
        for (int i = 0; i < n; i++) {
            cin >> L[i] >> R[i];
            A[i] = {L[i], R[i]};
        }
        sort(A.begin(), A.end());
        sort(L.begin(), L.end());
        sort(R.begin(), R.end());
        int ans = n;
        for (const auto& a : A) {
            int left = lower_bound(R.begin(), R.end(), a.first) - R.begin();
            int right = L.end() - upper_bound(L.begin(), L.end(), a.second);
            ans = min(ans, left + right);
        }
        cout << ans << '\n';
    }
    return 0;
}