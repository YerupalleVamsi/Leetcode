class Solution {
public:
const int MOD=1e9+7;
    int calp(int base, int exp, int lim){
        long long res=1;
        while(exp--){
            res*=base;
            if(res>lim) return lim+1; // return n+1 so we can return 0
        }
        return (int)res;
    }
    int rec(vector<vector<int>>&dp,int n,int x,int curr,int sum){
        if(sum == n ) return 1;
        if(sum>n) return 0;
        int p=calp(curr,x,n); // cal the power and stop if exceeds n
        if(p>n)return 0;
        if(dp[curr][sum]!=-1)return dp[curr][sum];
        long long nottake=rec(dp,n,x,curr+1,sum);
        long long take=rec(dp,n,x,curr+1,sum+p);
        return dp[curr][sum] = (int)((take+nottake)%MOD); // take all cases 

    }
    int numberOfWays(int n, int x) {
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return rec(dp,n,x,1,0);
    }
};