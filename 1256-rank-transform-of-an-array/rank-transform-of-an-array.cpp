class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& nums) {
        vector<int>res = nums;
        sort(res.begin(),res.end());
        unordered_map<int,int>mpp;
        int rank=0;
        for(int i=0;i<res.size();i++){
            if(!mpp.count(res[i])){
                rank++;
                mpp[res[i]] = rank;
            }
        }
        for(int i=0;i<nums.size();i++){
            nums[i] = mpp[nums[i]];
        }
        return nums;
    }
};