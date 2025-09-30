class Solution {
public:
    int rec(vector<int>&nums){
        if(nums.size()==1) return nums[0];
        vector<int>next;
        for(int i=0;i<nums.size()-1;i++){
            next.push_back((nums[i]+nums[i+1])%10);
        }
        // for(int i=0;i<next.size();i++){
        //     cout << next[i] << " ";
        // }
        // cout << endl;
        return rec(next);
    }
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        return rec(nums);
    }
};