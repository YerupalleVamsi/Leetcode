class Solution {
public:
   unsigned long long recur(int amount,vector<int>&coins,int curr_idx,vector<vector<unsigned long long>>&dp){
         if(amount == 0) return 1;
        if(curr_idx >= coins.size()) return 0;
        if(amount < 0) return 0;
        if(dp[curr_idx][amount]!=-1) return dp[curr_idx][amount];
        
        int cnt=0;
        long long  take = recur(amount-coins[curr_idx],coins,curr_idx,dp);
        long long not_take = recur(amount,coins,curr_idx+1,dp);
        return dp[curr_idx][amount]=take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned long long >> dp(n+1,vector<unsigned long long>(amount+1,-1));
        return recur(amount,coins,0,dp);
    }
};