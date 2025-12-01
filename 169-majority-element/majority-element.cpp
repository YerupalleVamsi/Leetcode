class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i:nums){
            if(mpp[i]>=n/2) return i;
            mpp[i]++;
        }
        return 0;
    }
};