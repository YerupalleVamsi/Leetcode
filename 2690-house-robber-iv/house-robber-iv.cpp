class Solution {
public:
bool check(vector<int>&nums,int m,int k){
    int n=nums.size();
    int i=0;
    int count=0;
    while(i<n){
        if(nums[i]<=m){
            count++;
                if(count==k)return true;
                i+=1;
        }
        i+=1;
    }
    return false;
}
    int minCapability(vector<int>& nums, int k) {
        int right=nums[0];
        int left=nums[0];
        int ans=right;
        for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > right) right = nums[i];
        if (nums[i] < left) left = nums[i];
    }
        while(left<=right){
            int mid=(left+right)/2;
            if(check(nums,mid,k)){
                ans=mid;
                right=mid-1;

            }
            else{
            left=mid+1;
            }
        }
        return ans;
    }
};