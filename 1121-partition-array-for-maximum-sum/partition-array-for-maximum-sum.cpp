class Solution {
public:
    int solve(vector<int>&nums,int k,int idx,vector<int>&dp){
        if(idx >= nums.size()) return 0;
        int res = 0;
        int maxi = -1;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx;i<nums.size() && i<idx+k;i++){
            maxi = max(maxi,nums[i]);
            res = max(res, maxi * (i-idx+1) + solve(nums,k,i+1,dp));
        }
        return dp[idx] = res;
    }
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,k,0,dp);
    }
};