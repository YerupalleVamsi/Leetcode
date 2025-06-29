class Solution {
public:
    int MOD=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        long long cnt=0;
        // number of subsets for a given set[n] = 2^n;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>two_power(n+1,1);
        for(int i=1;i<=n;i++){
            two_power[i]=(two_power[i-1]*2LL)%MOD;
        } 
        int low=0;
        int high=n-1;
        while(low<=high){
            if(nums[low]+nums[high]<=target){
                cnt=(cnt+two_power[high-low])%MOD;
                low++;
            }
            else{
                high--;
            }
            
        }
        return cnt;

        
    }
};