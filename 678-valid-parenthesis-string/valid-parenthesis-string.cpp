class Solution {
public:
    bool solve(string &s, int idx,int open, vector<vector<int>> &dp){
        if(open<0) return 0;
        if(idx==s.size()){
           return open==0;
        }
        if(dp[idx][open]!=-1) return dp[idx][open];
        if(s[idx]==')') return solve(s,idx+1,open-1,dp);
        if(s[idx]=='(') return solve(s,idx+1,open+1,dp);
        else
        return dp[idx][open] = solve(s,idx+1,open,dp) || solve(s,idx+1,open-1,dp) || solve(s,idx+1,open+1,dp);
    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(s,0,0,dp);
    }
};