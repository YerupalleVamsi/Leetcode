class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,bool>seen;
        int l=0;
        int max_sum=0;
        int curr_sum=0;
        for(int r=0;r<nums.size();r++){
            
            while(seen[nums[r]]){
                seen[nums[l]]=false;
                curr_sum-=nums[l];
                l+=1;
                
            }
            seen[nums[r]]=true;
            curr_sum+=nums[r];
            max_sum=max(max_sum,curr_sum);

        }
        return max_sum;
    }
};