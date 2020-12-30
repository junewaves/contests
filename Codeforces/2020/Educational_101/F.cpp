#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5;
int cnt[N];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &it : a) cin >> it;
    if (accumulate(a.begin(), a.end(), 1LL) - 2 * n < k) {
        cout << "-1\n";
        return 0;
    }
    sort(a.begin(), a.end(), greater<int>());
    cnt[0] = 1;
    cnt[1] = -1;
    int total = 0;
    for (int i = 0, j = 0; i < N - 1; i++) {
        total += cnt[i];
        cnt[i + 1] += cnt[i];
        if (total + cnt[i + 1] >= k) {
            cout << i + 1 << '\n';
            return 0;
        }
        while (cnt[i] > 0 && j < n) {
            int l = (a[j] - 1) / 2, r = a[j] - 1 - l;
            cnt[i + 2] += 2;
            cnt[i + 2 + l]--;
            cnt[i + 2 + r]--;
            cnt[i]--;
            total--;
            j++;
        }
    }
    assert(false);
}