class Solution {
public:
    bool backtrack(string &s, string &p,int i, int j,vector<vector<int>>&dp){
        if (j == p.size()) return i == s.size();
        if (i == s.size()) {
    // remaining pattern must be all '*'
        for (int k = j; k < p.size(); k++) {
            if (p[k] != '*') return false;
        }
        return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool take=false;
        if(s[i] == p[j] || p[j] == '?' ){
            take = backtrack(s,p,i+1,j+1,dp);
        }
        bool not_take=false;
        if(p[j] == '*'){
            take = backtrack(s,p,i+1,j,dp);
            not_take = backtrack(s,p,i,j+1,dp);
        }
        return dp[i][j]=take||not_take;
    }
    bool isMatch(string s, string p) {
        int len1=s.size();
        int len2=p.size();
    // int stars=0;
    // int q=0;
    // for(char c: p){
    //     if(c == '*'){
    //         stars++;
    //     }
    //     else if(c == '?')
    //         q++;
    //         }
    //     if(stars == 0 && len1!=len2) return false;
    //     else if(q==0 && len2==stars) return true;
    //     else if(stars+q == len2 && stars+q == len1) return true;
    //    else if(stars+q == len2 ){ 
    //     if(q==len1)
    //     return true;
    //     else
    //     return false;}
    vector<vector<int>>dp(len1+1,vector<int>(len2+1,-1));
        return backtrack(s,p,0,0,dp);
    }
};