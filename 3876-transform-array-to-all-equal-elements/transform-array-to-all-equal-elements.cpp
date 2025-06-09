class Solution {
public:
    bool canwedoit(vector<int> nums,int k,int target){
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]!=target){
                nums[i]*=-1;
                nums[i+1]*=-1;
                k--;
            }
            if(k<0)return false;
        }
        return nums[n-1]==target;
    }
    bool canMakeEqual(vector<int>& nums, int k) {
        // we can make all elements to 1 or -1
        bool plus1=canwedoit(nums,k,1);
        bool minus1=canwedoit(nums,k,-1);
        return plus1||minus1;
    }
};