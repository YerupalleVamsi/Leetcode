class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        unordered_map<int,int>seen;
        for(auto it:nums) seen[it]++;
        int outlier = INT_MIN;
        for(int i=0;i<n;i++){
            int req = total - 2*nums[i];
            if(seen.count(req)  && (req!= nums[i] || seen[total-2*nums[i]]>1)){
                outlier = max(outlier,total - 2*nums[i]);
            }
        }
        return outlier;
    }
};