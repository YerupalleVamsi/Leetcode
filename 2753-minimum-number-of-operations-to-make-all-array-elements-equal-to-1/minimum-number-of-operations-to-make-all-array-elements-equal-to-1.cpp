class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ones=0;
        for(int i:nums){
            if(i==1)
            ones++;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(gcd(nums[i],nums[i+1])==1){
                return nums.size()-ones;
            }
        }
        int res = INT_MAX;
        for(int i=0;i<nums.size()-1;i++)
        {
            int curr = nums[i];
            for(int j=i+1;j<nums.size();j++){
                int g = gcd(curr,nums[j]);
                curr=g;
                if(g==1){
                    res = min(res,j-i+1);
                }
            }
        }
                                  // create 1  + expand 1
        return res==INT_MAX? -1 : (res-1) + (nums.size()-1);
    }
};