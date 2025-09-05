class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int curr_sum=0;
        int min_len=INT_MAX;
        int l=0;
        for(int r=0;r<nums.size();r++){
            curr_sum+=nums[r];
            while(curr_sum>=target){
                min_len=min(min_len,r-l+1);
                curr_sum-=nums[l];
                l++;
            }
            
        }
        if(min_len==INT_MAX)return 0;
        return min_len;
    }
};