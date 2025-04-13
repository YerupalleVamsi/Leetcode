class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2==1)return false;
        int target=sum/2;
        vector<bool>dp(target+1);
        dp[0]=true;
        for(int i=1;i<=target;i++){
            dp[i]=false;
        }
        for(int i:nums){
            for(int j=target;j>=i;j--){
                dp[j]= dp[j] || dp[j-i];
                if(dp[target])return true;

            }
        }
        return false;

    }
};