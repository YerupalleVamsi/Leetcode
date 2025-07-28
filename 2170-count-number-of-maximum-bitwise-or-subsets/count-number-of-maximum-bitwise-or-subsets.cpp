class Solution {
public:
    void backtrack(vector<int>&nums,int&cnt,int curr,int curr_or,int target){
        if(curr==nums.size()){
        if(curr_or==target)
            cnt++;
            return;
        }
        backtrack(nums,cnt,curr+1,curr_or,target);
        int nextcurr=curr_or|nums[curr];
        backtrack(nums,cnt,curr+1,nextcurr,target);
        return;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int max_val=0;
        for(int i:nums){
            max_val|=i;
        }
        int cnt=0;
        backtrack(nums,cnt,0,0,max_val);
    return cnt;
    }
};