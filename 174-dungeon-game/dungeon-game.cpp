class Solution {
public:
    int rec(int r, int c,vector<vector<int>>&dg,vector<vector<int>>&dp){
        int n=dg.size();
        int m=dg[0].size();
        if(r > n-1 || c > m-1) return INT_MAX;
        if(dp[r][c]!=-1) return dp[r][c];
        if(r == n-1 && c == m-1) return max(1,1 - dg[r][c]);
        long long right=rec(r,c+1,dg,dp);
        long long down=rec(r+1,c,dg,dp);
        int req = min(right,down) - dg[r][c]; 
        return dp[r][c]=max(1,req);
        
    }
    int calculateMinimumHP(vector<vector<int>>& dg) {
        int r = dg.size();
        int c = dg[0].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));    
        return rec(0,0,dg,dp);
    }
};