#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int m = (i + j) / 2;
            if (target == nums[m])
                return m;
            else if (target < nums[m]) {
                if (target < nums[i] && nums[m] >= nums[i])
                    i = m + 1;
                else
                    j = m;
            } else if (target > nums[m]) {
                if (target > nums[j] && nums[m] <= nums[j])
                    j = m;
                else
                    i = m + 1;
            }
        }
        if (nums[i] == target)
            return i;
        else
            return -1;
    }
};
int main() {
    vector<int> input = { 4, 5, 6, 7, 8, 0, 1, 2 };
    Solution s;
    int n;
    cin >> n;
    cout << s.search(input, n) << endl;
}