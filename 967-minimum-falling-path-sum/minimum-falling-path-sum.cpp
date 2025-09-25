// class Solution {
// public:
//     int rec(int r,int c,vector<vector<int>>&dp , vector<vector<int>>&matrix){
//         int n=matrix.size();
//         int m=matrix[0].size();
//         if(c<0 || c >=m ) return INT_MAX;
//         if(r == n-1) return matrix[r][c];
//         if(dp[r][c]!=-1) return dp[r][c];
//         int l = rec(r+1,c-1,dp,matrix);
//         int mi = rec(r+1,c,dp,matrix);
//         int ri = rec(r+1,c+1,dp,matrix);
//         return dp[r][c] = matrix[r][c]+min({l,mi,ri});
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//          int res= INT_MAX;
//          for(int i=0;i<m;i++)
//          res=min(res,rec(0,i,dp,matrix));
//          return res;
//     }
// };
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>dp(matrix[0]);
        vector<int> new_dp(m);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0)
            new_dp[j] = matrix[i][j] + min(dp[j], dp[j+1]);
            else if (j == m - 1)
            new_dp[j] = matrix[i][j] + min(dp[j], dp[j-1]);
            else
            new_dp[j] = matrix[i][j] + min({dp[j], dp[j-1], dp[j+1]});
        }
        dp = new_dp; 
    }

        int res=INT_MAX;
        for(int i=0;i<dp.size();i++){
            res=min(res,dp[i]);
        }
        return res;
    }
};