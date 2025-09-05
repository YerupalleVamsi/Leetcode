class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total_sum=0;
        for(int i:nums)
        total_sum+=i;
        if(total_sum<x) return -1;
        int tar=total_sum-x;
        int l=0;
        int max_size=INT_MIN;
        int curr_sum=0;
        for(int r=0;r<nums.size();r++){
            curr_sum+=nums[r];
            while(curr_sum>tar){
                curr_sum-=nums[l];
                l++;
            }
            if(curr_sum==tar){
                max_size=max(r-l+1,max_size);
            }
        }
        if(max_size<0)return -1;
        return nums.size()-max_size;
    }
};