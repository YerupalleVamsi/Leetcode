class Solution {
public:
    int rec(vector<int>&prices,int idx,int transactions,vector<vector<int>>&dp){
        if(transactions == 4  || idx == prices.size()) return 0;
        if(dp[idx][transactions]!=-1) return dp[idx][transactions];
        int not_take = rec(prices,idx+1,transactions,dp);
        int take=0;
        bool buy = (transactions % 2 == 0);
        if(buy){
            take = -prices[idx] + rec(prices,idx+1,transactions+1,dp);
        } 
        else{
            take = prices[idx] + rec(prices,idx+1,transactions+1,dp);
        }
        return dp[idx][transactions]=max(take,not_take);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(4,-1));
        return rec(prices,0,0,dp);
    }
};