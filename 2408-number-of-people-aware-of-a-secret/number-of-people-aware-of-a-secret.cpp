class Solution {
public:
    int MOD=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // on ith day we got to know the secret
        // we can share the secret after i+delay days
        // we forget the secret after i+forget days
        vector<long long>dp(n);
        dp[0]=1;
        long long knows=0;
        for(int i=1;i<n;i++)
        {
            if(i-delay>=0) knows=(knows+dp[i-delay])%MOD;
            if(i-forget>=0) knows=(knows-dp[i-forget]+MOD)%MOD;
            dp[i]=knows;
        }
        long long she_knows=0;
        for(int i=n-forget;i<n;i++){
            she_knows=(she_knows+dp[i])%MOD;
        }
        return she_knows; // how many know at the end of day n
    }
};