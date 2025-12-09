class Solution {
public:
    const int MOD = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp_prev;
        unordered_map<int,int>mpp_next;
        long long zeros = 0;
        long long res=0;
        for(auto it:nums) mpp_next[it]++;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)zeros++;
            long long x = nums[i];
            mpp_next[x]--;
            mpp_prev[x]++;
            long long target = 1LL*x*2;
            
            if(target!=0 && mpp_prev.count(target) && mpp_next.count(target)){
            long long left = mpp_prev[target];
            long long right = mpp_next[target];
            long long cur = (1LL * left * right) % MOD;
            res = (res + cur) %MOD;
            }
        }
        res = (res + ((zeros*(zeros-1)*(zeros-2)*1LL)/6)%MOD)%MOD;
        return res%MOD;
    }
};