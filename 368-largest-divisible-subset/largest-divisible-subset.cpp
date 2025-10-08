class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>prev(n,-1);
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        int last_idx = 0;
        for(int i=1;i<n;i++){
            for(int j = 0; j<i;j++){
                if(nums[i]%nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = 1 + dp[j];
                    prev[i] = j; 
                }
            }
            if(dp[i] >  dp[last_idx]){
                last_idx = i;
            }
        }
        vector<int> res;
        for (int i = last_idx; i >= 0; i = prev[i]) {
            res.push_back(nums[i]);
        }
        return res;
    }
};