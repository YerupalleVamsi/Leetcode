class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxdiff=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    int diff=nums[j]-nums[i];
                    maxdiff=max(diff,maxdiff);
                }
            }
        }
    
        return maxdiff;
    }
};