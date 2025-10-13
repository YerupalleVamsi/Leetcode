class Solution {
public:
    long long solve(vector<int>&nums,int l,int r,vector<vector<int>>&dp){
        if (l > r) return 0;
        if (l == r) return nums[l-1] * nums[l] * nums[r+1];
        if(dp[l][r]!=-1) return dp[l][r];
        int coins = 0;
        for(int k=l;k<=r;k++){
            long long curr = nums[l-1]*nums[k]*nums[r+1] + solve(nums,l,k-1,dp) + solve(nums,k+1,r,dp);
            if(curr > coins)
            coins = curr;
        }

        return dp[l][r] = coins;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
         nums.push_back(1);
         vector<vector<int>>dp(nums.size()+2,vector<int>(nums.size()+2,-1));
        return solve(nums,1,nums.size()-2,dp);
    }
};