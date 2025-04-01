class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
    vector<long long>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int take = questions[i][0];
            int jump = questions[i][1];

            int nextQ=min(n,i+jump+1);
            dp[i]=max(dp[i+1],take+dp[nextQ]);
        }
        return dp[0];
    }
};