class Solution {
public:
    int rec(vector<int>& nums, int target, int curr_idx, int current_sum, vector<vector<int>>& dp, int offset) {
        if (curr_idx == nums.size()) {
            return current_sum == target ? 1 : 0;
        }
        if (dp[curr_idx][current_sum + offset] != -1) {
            return dp[curr_idx][current_sum + offset];
        }
        int add = rec(nums, target, curr_idx + 1, current_sum + nums[curr_idx], dp, offset);
        int subtract = rec(nums, target, curr_idx + 1, current_sum - nums[curr_idx], dp, offset);
        return dp[curr_idx][current_sum + offset] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        if (abs(target) > total_sum) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(2 * total_sum + 1, -1));
        return rec(nums, target, 0, 0, dp, total_sum);
    }
};