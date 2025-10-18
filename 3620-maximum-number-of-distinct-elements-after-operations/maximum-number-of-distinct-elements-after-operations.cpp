class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        int prev = INT_MIN;
        for(int i:nums)
        {
            int upper = i+k;
            int lower = i-k;
            if(prev < lower){
                prev = lower;
                cnt++;
            }
            else if(prev <  upper){
                prev++;
                cnt++;
            }
        }
        return cnt;
    }
};