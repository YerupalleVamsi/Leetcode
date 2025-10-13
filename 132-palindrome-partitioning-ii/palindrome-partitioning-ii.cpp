class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}
    int solve(string &s,int idx,vector<int>&dp){
        if(idx >= s.size())return -1;
        if(dp[idx]!=-1) return dp[idx];
        int cuts=INT_MAX;
        for(int i = idx ; i<s.size() ;i++){
            int curr_cuts=0;
            if(isPalindrome(s,idx,i)){
            curr_cuts = 1 + solve(s,i+1,dp);
            cuts = min(curr_cuts,cuts);
            }
            
        }
        return dp[idx]=cuts;
    }
    int minCut(string s) {
        // string curr ="";
        vector<int>dp(s.size()+1,-1);
        return solve(s,0,dp);
    }
};