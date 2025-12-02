class Solution {
public:
    const int MOD = 1e9+7;
    const long long INV2 = 500000004;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>mpp;
        for(auto it : points){
            mpp[it[1]]++;
        }
        long long sum=0;
        long long sq=0;
        for(auto [k,v]:mpp)
        {   
            long long comb = ((long long)v * (v - 1) / 2) % MOD;
            sum = (sum + comb)%MOD;
            sq = (sq + comb*comb) %MOD;
        }
        int res = (((sum*sum) %MOD - sq + MOD))%MOD;
        res = (res * INV2) % MOD;
        return (int)res;
    }
};