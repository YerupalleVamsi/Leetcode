class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        // to swap two numbers --> have a common set bit 
        int k=~0; // 111111
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                k&=nums[i];
            }
        }
        if(k==~0)return 0;
        return k;
    }
};