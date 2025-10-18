class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // nums.insert(nums.end(),nums.begin(),nums.end());
        int maxi = nums[0];
        int mini = nums[0];
        int curr_max=nums[0],curr_min = nums[0];
        int n = nums.size();
        int total = nums[0];
        for(int i=1;i<n;i++){
            curr_max = max(curr_max+nums[i],nums[i]);
            maxi = max(maxi,curr_max);
            curr_min = min(curr_min+nums[i],nums[i]);
            mini = min(mini,curr_min);
            total+=nums[i];
        }
        if(mini  == total) return maxi;
        return  max(maxi,total-mini);
    }
};