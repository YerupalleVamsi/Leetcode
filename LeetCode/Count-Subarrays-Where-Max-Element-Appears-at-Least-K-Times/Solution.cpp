class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }
        int l=0;
        long long ans=0;
        long long cnt=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==maxi){
                cnt++;
            }
            while(cnt>=k){
                if(nums[l]==maxi){
                    cnt--;
                }
                l++;
            }
            ans+=l;
        }return ans;
    }
};