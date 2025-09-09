class Solution {
public:
    int mini=INT_MAX;
    int dfs(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1){
            return INT_MAX;
        }
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        
        int r=dfs(grid,i+1,j,dp);
       int d=dfs(grid,i,j+1,dp);
        return dp[i][j]=grid[i][j]+min(d,r);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return dfs(grid,0,0,dp);
        
    }
};