#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<int> a;
bool check(int target, bool take) {
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (!take || a[i] <= target) {
            len++;
            take = !take;
        }
    }
    return len >= k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    a = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int lo = 0, hi = 1e9, ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        // check for if mid is on odd or even index the length can be >= k
        if (check(mid, true) || check(mid, false)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}