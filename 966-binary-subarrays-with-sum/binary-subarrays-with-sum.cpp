class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return lessthan(nums, goal) - lessthan(nums, goal - 1);
    }
    // we find the subarrays which have sum <= goal && sum<=goal-1 
    // we can get the subarrays which have sum exactly == goal by taking their diff
    
    int lessthan(vector<int>& nums, int target) {
        if (target < 0) return 0;

        int ans = 0;
        int start = 0;
        int sum = 0;

        for (int end = 0; end < nums.size(); end++) {
            sum += nums[end]; 
            while (sum > target) { 
                sum -= nums[start++];
            }
            ans += end - start + 1; 
        }

        return ans;
    }
};
