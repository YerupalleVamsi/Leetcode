class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int currl[n];
        fill_n(currl,n,1);
        int ans=1;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(currl[j]+1>currl[i]){
                        currl[i]=currl[j]+1;
                    }
                }
             ans=max(ans,currl[i]);   
            }
        }return ans;
    }
};