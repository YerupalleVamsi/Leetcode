class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dp(r,vector<int>(c,0));
        long long ans = 0;
        for(int i=r-1;i>=0;i--){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    dp[i][j]=1;
                    if(i+1<r && j-1>=0 && j+1<c)
                        dp[i][j]=1+min({dp[i+1][j],dp[i+1][j-1],dp[i+1][j+1]});
                    ans += dp[i][j]-1;
                }
            }
        }

        dp.assign(r, vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    dp[i][j]=1;
                    if(i-1>=0 && j-1>=0 && j+1<c)
                        dp[i][j]=1+min({dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]});
                    ans += dp[i][j]-1;
                }
            }
        }

        return ans;
    }
};
