class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        // so by getting mod of every element in nums we will get some pattern for the longest subsequence
        // that is the possible remainders that we get by dividing the nums with k  in range [0,k-1]
        // we can get the same number as remainder right u know some basic math nigga

        // lets take k=3 and size of subsequence = 4 then we have some patterns like
        //  0 1 0 1
        //  1 0 1 0
        //  2 1 2 1
        //  1 2 1 2 
        //  2 1 2 1 
        //  2 0 2 0
        //  0 2 0 2

        // these are the patterns you will get if we get a valid subsequence from a given nums array

        // so we can create a dp(K*K)
        vector<vector<int>>dp(k,vector<int>(k,0));
        int max_len=0;
        int n=nums.size();
        if(k==1){
            return n;
        } // base case if k==1 all remainders will be same so max_len will be n

        for(int num:nums){
            int mod=num%k;
        for(int rem=0;rem<k;rem++){ // traverse through all remainders 
            dp[rem][mod]=dp[mod][rem]+1;
            max_len=max(max_len,dp[rem][mod]);
    
        }}
        return max_len;

    }
};