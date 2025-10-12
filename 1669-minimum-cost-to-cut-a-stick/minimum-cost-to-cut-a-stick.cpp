class Solution {
public:
    int solve(int st,int end,int l,int r,vector<int>&cuts,vector<vector<int>>&dp){
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int mini = 1e9;
        for(int k=l;k<=r;k++){
            int curr = (end-st) + solve(st,cuts[k],l,k-1,cuts,dp) + solve(cuts[k],end,k+1,r,cuts,dp);
            if(curr<mini) mini=curr;
        }
    return dp[l][r]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
        return solve(0,n,0,cuts.size()-1,cuts,dp);
    }
};