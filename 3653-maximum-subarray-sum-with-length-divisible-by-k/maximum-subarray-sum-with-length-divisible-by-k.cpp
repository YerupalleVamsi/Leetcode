class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>presum(n+1,k);
        for(int i=0;i<n;i++)
        presum[i+1] = nums[i] + presum[i];
        long long res = LLONG_MIN;
        for(int i=0;i<k;i++){
            long long sum = 0;
            for(int j=i;j+k<=n;j+=k){
               long long curr = presum[j+k] - presum[j];
                sum = max(curr,sum+curr);
                res=max(sum,res);
            }
        }
        return res;
    }
};