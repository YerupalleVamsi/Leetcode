class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return false;
       unordered_map<int,int>mpp;
       for(int i:nums)
       mpp[i]++;
        for(auto it:mpp)
        if(it.second > n/k) return false;
        return true;
    }
};