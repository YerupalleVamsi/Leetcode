class Solution {
public:
    int findLHS(vector<int>& nums) {
    int lhs=0;
    int n=nums.size();
    int l=0;
    sort(nums.begin(),nums.end());
    for(int r=0;r<n;r++){
        while(nums[r]-nums[l]>1){
            l++;
        }
        if(nums[r]-nums[l]==1){
            lhs=max(lhs,r-l+1);
        }
    }
    return lhs;

    }
};