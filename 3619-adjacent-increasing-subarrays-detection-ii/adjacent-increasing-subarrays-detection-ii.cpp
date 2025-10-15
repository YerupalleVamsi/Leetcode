class Solution {
public:
     bool isinc(vector<int>&nums,int k){
        int prev = 0;
        int curr =1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] > nums[i-1]){
                curr++;
            }
            else{
                prev = curr;
                curr = 1;
            }
            if(curr >= 2*k ){
                return true;
            }
            if(min(prev,curr) >= k){
                return true;
            }
        }
        return false;
     }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int max_len=1;
        int curr_len=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]>nums[i]){
                curr_len++;
            }
            else{
                curr_len=0;
            }
            max_len=max(max_len,curr_len+1);
        }
       int low = 0;
       int high = max_len;
       int res=INT_MIN;
       while(low<=high){
        int mid = low + (high-low)/2;
        if(isinc(nums,mid)){
            res = max(res,mid);
            low = mid+1; 
        }
        else{
            high = mid - 1;
        }
       }
       return res;
    }
};