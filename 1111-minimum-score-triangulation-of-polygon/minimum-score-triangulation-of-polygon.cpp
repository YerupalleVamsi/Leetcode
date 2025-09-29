class Solution {
public:
    int mcm(int i,int j,vector<int>&values,vector<vector<int>>&dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=INT_MAX;
        for(int k=i;k<j;k++){
            int cost = mcm(i,k,values,dp)+mcm(k+1,j,values,dp)+values[i-1]*values[k]*values[j];
            res=min(res,cost);
        }
        return dp[i][j]=res;
    } 
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return mcm(1,n-1,values,dp);
    }
};