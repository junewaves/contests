#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums) {
    int n = nums.size(), s = 0, max_len = 0;
    unordered_map<int, int> m;
    m[0] = -1;
    for (int i = 0; i < n; i++) {
        s += nums[i] ? 1 : -1;
        if (m.count(s))
            max_len = max(max_len, i - m[s]);
        else
            m[s] = i;
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