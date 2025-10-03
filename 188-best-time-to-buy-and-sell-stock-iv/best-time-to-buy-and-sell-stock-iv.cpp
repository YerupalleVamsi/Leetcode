// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
        
//     }
// };
class Solution {
public:
    int rec(vector<int>&prices,int idx,int transactions,vector<vector<int>>&dp,int k){
        if(transactions == 2*k  || idx == prices.size()) return 0;
        if(dp[idx][transactions]!=-1) return dp[idx][transactions];
        int not_take = rec(prices,idx+1,transactions,dp,k);
        int take=0;
        bool buy = (transactions % 2 == 0);
        if(buy){
            take = -prices[idx] + rec(prices,idx+1,transactions+1,dp,k);
        } 
        else{
            take = prices[idx] + rec(prices,idx+1,transactions+1,dp,k);
        }
        return dp[idx][transactions]=max(take,not_take);
    }
    int maxProfit(int k,vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2*k,-1));
        return rec(prices,0,0,dp,k);
    }
};