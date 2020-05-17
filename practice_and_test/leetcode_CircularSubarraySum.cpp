#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // kadane's algrithm
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size(), ans1 = INT_MIN;
        for (int i = 0, sum = 0; i < n; i++) {
            sum += A[i];
            ans1 = max(ans1, sum);
            sum = max(sum, 0);
        }
        if (ans1 < 0)  // all of A is negative
            return ans1;
        int ans2 = INT_MAX, sum_all = 0;
        for (int i = 0, sum = 0; i < n; i++) {
            sum_all += A[i];
            sum += A[i];
            ans2 = min(ans2, sum);
            sum = min(sum, 0);
        }
        ans2 = sum_all - ans2;
        return max(ans1, ans2);
    }
    /*  prefix sum + monoqueue
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        vector<int> prefix(2 * n + 1);
        for (int i = 1; i <= 2 * n; i++) {
            prefix[i] = prefix[i - 1] + A[(i - 1) % n];
        }
        int ans = INT_MIN;
        deque<int> q = { 0 };
        for (int i = 1; i <= 2 * n; i++) {
            if (!q.empty() && i - q.front() > n) {
                q.pop_front();
            }
            ans = max(ans, prefix[i] - prefix[q.front()]);
            while (!q.empty() && prefix[q.back()] > prefix[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return ans;
    }*/
};

int main() {
    vector<int> input = { 5, -3, 5 };
    for (int i : input)
        cout << i << " ";
    cout << endl;
    Solution s;
    cout << s.maxSubarraySumCircular(input) << endl;
}