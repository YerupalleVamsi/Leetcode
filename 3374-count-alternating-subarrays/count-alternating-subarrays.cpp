class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long cnt=1;
        long long size=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])size=1;
            else
            {
                size+=1;
                
            }
            cnt+=size;
        }
        return cnt;
    }
};