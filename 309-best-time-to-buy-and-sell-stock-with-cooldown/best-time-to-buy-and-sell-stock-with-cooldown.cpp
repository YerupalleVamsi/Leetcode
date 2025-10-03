class Solution {
public:
    int rec(vector<int>&prices,int idx,int taken,vector<vector<int>>&dp){
        if(idx >= prices.size()) return 0;
       int profit = 0; 
        if(dp[idx][taken]!=-1) return dp[idx][taken];
        if(!taken){
           int take = -prices[idx] + rec(prices,idx+1,1,dp);
           int not_take  =  rec(prices,idx+1,0,dp);
           profit=max(take,not_take); 
        }
        else{
            int sell = prices[idx] + rec(prices,idx+2,0,dp);
            int not_sell = rec(prices,idx+1,1,dp);
            profit=max(sell,not_sell);
        }
        return dp[idx][taken]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1 , vector<int>(2,-1));
        return rec(prices,0,0,dp);
    }
};