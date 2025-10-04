class Solution {
public:
    int rec(vector<int>&prices,int fee,int idx,int exchanges,vector<vector<int>>&dp){
        if(idx ==  prices.size()) return 0;
        bool take = exchanges % 2 == 0;
        if(dp[idx][take]!=-1) return dp[idx][take];
        int max_profit=0;
        if(take){
            int buy = -prices[idx] + rec(prices,fee,idx+1,exchanges+1,dp);
            int not_buy = rec(prices,fee,idx+1,exchanges,dp);
            max_profit = max(buy,not_buy);
        }
        else{
            int sell = prices[idx]-fee + rec(prices,fee,idx+1,exchanges+1,dp);
            int not_sell = rec(prices,fee,idx+1,exchanges,dp);
            max_profit =  max(sell,not_sell); 
        }
        return dp[idx][take] =  max_profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return rec(prices,fee,0,0,dp);
    }
};