class Solution {
public:
    bool isinc(vector<int>&nums,int st,int k){
        for(int i=st;i<st+k-1;i++){
            // cout << "func" << endl;
            // cout << nums[i] << endl;
            if(nums[i]>=nums[i+1])return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k==1) return true;
        for(int i=0;i<=nums.size()-2*k;i++){
            if(isinc(nums,i,k) && isinc(nums,i+k,k)){
                return true;
            }
        }
        return false;
    }
};