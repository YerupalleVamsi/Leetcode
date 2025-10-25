class Solution {
public:
    const int MOD = 1e9+7;
    int solve(int idx, vector<vector<int>>&mat,vector<vector<int>>&dp,int curr_gcd){
        if(idx == mat.size()){
            if(curr_gcd == 1) return 1;
            else return 0;
        }
        if(dp[idx][curr_gcd]!=-1) return dp[idx][curr_gcd];
        int res=0;
        for(int i=0;i<mat[0].size();i++){
            res = (res+solve(idx+1,mat,dp,gcd(mat[idx][i],curr_gcd)))%MOD;
        }
        return dp[idx][curr_gcd] = res%MOD;
    }
    int countCoprime(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dp(n,vector<int>(1e5,-1));
        return solve(0,mat,dp,0);
    }
};