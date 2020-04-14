#include <bits/stdc++.h>
using namespace std;
int combinationSum4(vector<int>& nums, int target) {
    vector<long long> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < target; i++) {
        for (int n : nums) {
            if (i + n <= target) {
                dp[i + n] += dp[i];
                assert(dp[i + n] >= 0);
            }
        }
    }
    return dp[target];
}
class Solution {
public:
    static int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        dp[target] = recur(dp, nums, target);
        return dp[target];
    }
    static int recur(vector<int>& dp, vector<int>& nums, int target) {
        if (target < 0)
            return 0;
        if (dp[target] >= 0)
            return dp[target];
        int ans = 0;
        for (int n : nums) {
            ans += recur(dp, nums, target - n);
        }
        return dp[target] = ans;
    }
};
int main() {
    vector<int> input = { 1, 2, 3 };
    cout << Solution::combinationSum4(input, 4) << endl;
}