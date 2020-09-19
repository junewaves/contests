#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int64_t n, x, m;
    cin >> n >> x >> m;
    vector<int> cnt(m), cand, cand2;
    for (int64_t i = x; cnt[i] < 2;) {
        cnt[i]++;
        if (cnt[i] == 1)
            cand.push_back(i);
        else if (cnt[i] == 2)
            cand2.push_back(i);
        i = i * i % m;
    }
    int len1 = 0, len2 = 0;
    int64_t sum1 = 0, sum2 = 0;
    for (int i : cand) {
        if (cnt[i] == 1)
            len1++, sum1 += i;
        else if (cnt[i] == 2)
            len2++, sum2 += i;
        else 
            assert(false);
    }
    // cout << len1 << ' ' << len2 << '\n';
    int64_t ans = 0;
    if (n <= len1 + len2) {
        for (int i = 0; i < n; i++) {
            ans += cand[i];
        }
    } else {
        n -= len1;
        int64_t l = n / len2;
        int64_t r = n % len2;
        int64_t sum3 = 0;
        for (int i = 0; i < r; i++)
            sum3 += cand2[i];
        ans = sum1 + sum2 * l + sum3;
    }
    cout << ans << '\n';
    return 0;
}