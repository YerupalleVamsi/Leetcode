class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>>max_heap;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            max_heap.push({nums[i],i});
        }
        vector<int>idx;
        while(k>0){
            auto it=max_heap.top();
            max_heap.pop();
            idx.push_back(it.second);
            k--;
        }
        sort(idx.begin(),idx.end());
        for(int i=0;i<idx.size();i++){
            res.push_back(nums[idx[i]]);
        }
        return res;
        
    }
};
