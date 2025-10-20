class Solution {
public:
    int minimumCardPickup(vector<int>& nums) {
        int res=INT_MAX;
        unordered_map<int,int>seen;
        for(int r=0;r<nums.size();r++){
            if(seen.find(nums[r])!=seen.end()){
                res=min(res,r-seen[nums[r]]+1);
            }
            seen[nums[r]]=r;
        }
        return res==INT_MAX ? -1 : res;
    }
};