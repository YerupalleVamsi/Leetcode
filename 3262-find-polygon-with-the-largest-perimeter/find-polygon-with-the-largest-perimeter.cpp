class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long curr_sum  = 0;
        sort(nums.begin(),nums.end());
        long long res = -1;
        for(int i=0;i<nums.size();i++){
            if(curr_sum > nums[i] ){
                res = curr_sum + nums[i];
            }
              curr_sum+=nums[i];
        }
        return res;
    }
};