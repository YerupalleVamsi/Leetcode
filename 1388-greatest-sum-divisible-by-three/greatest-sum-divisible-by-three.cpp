class Solution {
public:
    int solve(int idx,int rem,vector<int>&nums,vector<vector<int>>&dp){
        if(idx>=nums.size()){
            if(rem==0) return 0;
            return INT_MIN;
        }
        if(dp[idx][rem]!=-1) return dp[idx][rem];
        int take = nums[idx] + solve(idx+1,(rem+nums[idx])%3,nums,dp);
        int skip = solve(idx+1,rem,nums,dp);
        return dp[idx][rem] = max(take,skip);
    }
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(3,-1));
        return solve(0,0,nums,dp);
    }
};