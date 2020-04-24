#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<ll> s, ps;
ll splitSum(int i, int j) {
    if (i >= j)
        return 0;
    if (j - i == 1)
        return s[i] + s[j];
    ll sum = ps[j] - (i == 0 ? 0 : ps[i - 1]);
    ll partSum = 0, min_diff = LONG_LONG_MAX;
    int split_index = 0;
    for (int a = i + 1; a <= j; a++) {
        partSum += s[a - 1];
        if (min_diff > abs(sum - 2 * partSum)) {
            min_diff = abs(sum - 2 * partSum);
            split_index = a;
        }
    }
    // printf("%d\n", split_index);
    ll left = splitSum(i, split_index - 1);
    ll right = splitSum(split_index, j);
    // printf("%d %d %d\n", left, right, sum);
    return left + right + sum;
}
int main() {
    int sum = 0;
    scanf("%d", &n);
    s.reserve(n);
    ps.reserve(n);
    for (int i = 0; i < n; i++) {
        int y;
        scanf("%d", &y);
        sum += y;
        s.push_back(y);
        ps.push_back(sum);
    }
    ll ans = splitSum(0, n - 1);
    printf("%lld\n", ans);
}
