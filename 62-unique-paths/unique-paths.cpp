class Solution {
public:
    int rec(vector<vector<int>>&dp,int i,int j){
        int m=dp.size();
        int n=dp[0].size();
         
        if(i>m-1 || i<0 || j>n-1 || j<0 )return 0;
        if(i==m-1 && j == n-1) return 1;
        if(dp[i][j]!=0) return dp[i][j];
        
        int down=rec(dp,i+1,j);
        int right=rec(dp,i,j+1);
        return dp[i][j]=down+right;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n));
        return rec(dp,0,0);
        
    }
};