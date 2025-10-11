class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int lis = 1;
        vector<int>cnts(n,1);
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i] && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    cnts[i] = cnts[j];
                }
                else if(nums[j] < nums[i] && 1+dp[j] == dp[i]){
                cnts[i]+=cnts[j];
                }
            }
            lis=max(dp[i],lis);

        }
       int res=0;
       for(int i=0;i<n;i++){
        if(dp[i] == lis) res += cnts[i]; // is equal to max_len then cnt
       }
       return res;
    }
};