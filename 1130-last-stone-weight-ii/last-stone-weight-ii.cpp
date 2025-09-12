class Solution {
public:
int sum=0;
    int rec(vector<int>&stones,int idx,int curr_sum,vector<vector<int>>&dp){
        if(idx==stones.size())
        {
            return abs(curr_sum);
        }
        if(dp[idx][curr_sum+sum]!=-1) return dp[idx][curr_sum+sum];
       int p = rec(stones,idx+1,curr_sum+stones[idx],dp);
       int n = rec(stones,idx+1,curr_sum-stones[idx],dp);

        return dp[idx][curr_sum+sum] = min(p,n);
    }
    int lastStoneWeightII(vector<int>& stones) {
        // select 2 stones 
        // return the min after the operations
        int n=stones.size();
        for(int i:stones)
        sum+=i;
        vector<vector<int>> dp(n+1, vector<int>(2*sum+1,-1)); // why 2*sum+1 ? : at max we have sum if we add all and if we subtract all then we left with -sum but we can represent that in vector so we [-sum,sum] --> [0,2*sum+1]
        return rec(stones,0,0,dp);
    }
};