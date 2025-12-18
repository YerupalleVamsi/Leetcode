class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return nums[0]==k? 1: 0;
        int cnt=0;
        long long lcm_=1;
        for(int i=0;i<nums.size();i++){
            lcm_=1;
            for(int j=i;j<nums.size();j++){
                lcm_ = lcm(lcm_,nums[j]);
                if(lcm_>k)break;
                if(lcm_==k) cnt++;   
            }
        }
        return cnt;
    }
};