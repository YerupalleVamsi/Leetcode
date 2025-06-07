class Solution {
public:
    int count(vector<int>&nums,int k,int maxlimit){
        int cnt=1,limit=0;
        for(int i=0;i<nums.size();i++){
            if(limit+nums[i]>maxlimit){
                limit=nums[i];
                cnt++;
            }
            else{
                limit+=nums[i];
            }
        }
        return cnt;

    }
    int splitArray(vector<int>& nums, int k) {
        int high=0,low=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            high+=nums[i];
            low=max(low,nums[i]);
        }
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            int nsubarr=count(nums,k,mid);
            if(nsubarr<=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        return ans;
    }
};