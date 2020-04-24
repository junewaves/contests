#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> s, ps;
int splitSum(int i, int j) {
    if (i >= j)
        return 0;
    if (j - i == 1)
        return s[i] + s[j];
    int sum = ps[j] - (i == 0 ? 0 : ps[i - 1]);
    int partSum = 0, min_diff = INT_MAX;
    int split_index = 0;
    for (int a = i + 1; a <= j; a++) {
        partSum += s[a - 1];
        if (min_diff > abs(sum - 2 * partSum)) {
            min_diff = abs(sum - 2 * partSum);
            split_index = a;
        }
    }
    // printf("%d\n", split_index);
    if (j - i == 1)
        return s[i] + s[j];
    int left = splitSum(i, split_index - 1);
    int right = splitSum(split_index, j);
    // printf("%d %d %d\n", left, right, sum);
    return left + right + sum;
}
int main() {
    int sum = 0;
    scanf("%d", &n);
    s.reserve(n);
    ps.reserve(n);
    for (int i = 0; i < n; i++) {
        int y = 1;
        scanf("%d", &y);
        sum += y;
        s.push_back(y);
        ps.push_back(sum);
    }
    int ans = splitSum(0, n - 1);
    printf("%d\n", ans);
    fflush(stdout);
}
