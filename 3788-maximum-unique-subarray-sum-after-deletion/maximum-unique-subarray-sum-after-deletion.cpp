class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>s;
        int n=nums.size();
        if(n==1)return nums[0];
        int max_sum=0;
        for(int i:nums){
            s.insert(i);
        }
        for(int i:s){
            if(i>0){
                max_sum+=i;
            }
        }
        if(max_sum>0){
            return max_sum;
        }
        return *s.rbegin();
    }
};