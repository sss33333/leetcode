/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (38.40%)
 * Likes:    34970
 * Dislikes: 3245
 * Total Accepted:    5.6M
 * Total Submissions: 14.5M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation: 
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not
 * matter.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 3) return res;
        
        res.reserve(n / 3); // 预分配（经验值）

        for (int i = 0; i < n - 2; ++i) {
            int a = nums[i];
            if (a > 0) break; // 后续全正，无解
            
            // 强剪枝1：最小三数和 > 0
            if (a + nums[i + 1] + nums[i + 2] > 0) break;
            
            // 强剪枝2：当前数 + 最大两数 < 0 → 无解
            if (a + nums[n - 2] + nums[n - 1] < 0) continue;
            
            // 去重
            if (i > 0 && a == nums[i - 1]) continue;

            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = a + nums[j] + nums[k];
                if (sum == 0) {
                    res.push_back({a, nums[j], nums[k]});
                    // 跳过重复
                    while (j < k && nums[j] == nums[j + 1]) ++j;
                    //while (j < k && nums[k] == nums[k - 1]) --k;
                    ++j;
                    //--k;
                } else if (sum < 0) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        return res;
    }
};
// @lc code=end

