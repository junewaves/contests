#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        else
            return splitSearch(nums, 0, nums.size() - 1, target);
    }
    int splitSearch(vector<int>& nums, int i, int j, int target) {
        if (i == j)
            return (nums[i] == target ? i : -1);
        int m = (i + j) / 2;
        if (nums[m] < target) {
            if (target <= nums[j]) {
                return binarySearch(nums, m + 1, j, target);
            } else {
                return max(splitSearch(nums, i, m, target),
                           splitSearch(nums, m + 1, j, target));
            }
        } else if (target < nums[m]) {
            if (nums[i] <= target) {
                return binarySearch(nums, i, m, target);
            } else {
                return max(splitSearch(nums, i, m, target),
                           splitSearch(nums, m + 1, j, target));
            }
        } else {
            return m;
        }
    }
    int binarySearch(vector<int>& nums, int i, int j, int target) {
        while (i != j) {
            int m = (i + j + 1) / 2;
            if (nums[m] > target) {
                j = m - 1;
            } else {
                i = m;
            }
        }
        if (nums[i] == target)
            return i;
        else
            return -1;
    }
};
int main() {
    //[['1','1','1','1','0'],['1','1','0','1','0'],['1','1','0','0','0'],['0','0','0','0','0']]
    vector<int> input = { 4, 5, 6, 7, 8, 1, 2, 3 };
    Solution s;
    // int n;
    // cin >> n;
    cout << s.search(input, 8) << endl;
}