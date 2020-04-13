#include <bits/stdc++.h>
using namespace std;
// int findMaxLength(vector<int>&);
// int devide(vector<int>& s, int l, int r) {
//     if (r - l <= 1)
//         return 0;
//     int m = (l + r) / 2;
//     int left = devide(s, l, m);
//     int right = devide(s, m, r);
//     int m1 = m + 1, m2 = m - 1;
//     int len = 0;
//     while (m1 <= (int)s.size() && m2 >= 0) {
//         if ((s[m1] - s[m2]) * 2 == m1 - m2) {
//             len = m1 - m2;
//         }
//         m1++, m2--;
//     }
//     return max({ len, right, left });
// }

int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    vector<int> s(n + 1);
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = nums[i - 1] + s[i - 1];
    }
    int max_len = 0;
    for (int i = 0; i <= n - max_len; i++) {
        for (int j = i + max_len + 2; j <= n; j += 2) {
            if ((s[j] - s[i]) * 2 == j - i) {
                max_len = max(max_len, j - i);
            }
        }
    }
    return max_len;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    char c;
    int n0 = 0, n1 = 0, n;
    cin >> n;
    vector<int> input;
    input.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        cin >> c;
        n0 += 1 - input[i];
        n1 += input[i];
    }
    cout << n0 << " " << n1 << endl;
    // vector<int> input = { 0, 1 };
    clock_t start = clock();
    cout << findMaxLength(input) << endl;
    clock_t end = clock() - start;
    cout << (int)end << endl;
}