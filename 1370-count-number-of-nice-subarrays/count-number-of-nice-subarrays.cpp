class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return paimon(nums,k)-paimon(nums,k-1);
    }
    int paimon(vector<int>&nums,int k){
        if(k<0)return 0;
        int n=nums.size();
        int odds=0;
        int st=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                odds++;
            }
            while(odds>k){
                if(nums[st]&1){
                    odds--;
                }
                st++;
            }
            ans+=i-st+1;
        }
        return ans;
    }
};