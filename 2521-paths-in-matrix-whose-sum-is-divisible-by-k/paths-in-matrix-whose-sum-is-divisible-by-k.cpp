class Solution {
public:
    const int MOD = 1e9+7;
    int solve(int i,int j,int rem,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp,int k){
        int n=grid.size();
        int m = grid[0].size();
        if(i>=n || j>=m || i<0 || j<0) return 0; 
        if(i==n-1 && j==m-1 ){
            return ((rem + grid[i][j]) % k == 0) ? 1 : 0;
        }
        if(dp[i][j][rem]!=-1) return dp[i][j][rem];
         long long r = solve(i, j+1, (rem + grid[i][j]) % k, grid, dp, k);
        long long d  = solve(i+1, j,(rem + grid[i][j]) % k, grid, dp, k);

        return dp[i][j][rem] = (d+r)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));        
    return solve(0,0,0,grid,dp,k) % MOD;
    }
};