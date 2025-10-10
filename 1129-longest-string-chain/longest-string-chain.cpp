class Solution {
public:
    int solve(vector<string>&words,string curr,set<string>&s,unordered_map<string,int>&dp){
        if(dp.find(curr)!=dp.end())return dp[curr];
        if(s.find(curr)==s.end()){
            return 0;
        }
        int res = 1;
        for(int i=0;i<curr.size();i++){
            string next = curr;
            next.erase(i,1);
            res=max(res,1+solve(words,next,s,dp));
        }
        return dp[curr]=res;
    }
    int longestStrChain(vector<string>& words) {
        // ["a","b","ba","bca","bda","bdca"]
        // a ba bda bdca
        int n= words.size();
        set<string> s(words.begin(),words.end());
        int maxi=INT_MIN;
        unordered_map<string,int>dp;
        for(int i=0;i<n;i++)
            maxi = max(maxi,solve(words,words[i],s,dp));
        return maxi;
    }
};