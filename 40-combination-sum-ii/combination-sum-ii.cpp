class Solution {
public:
    void rec(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>curr, int idx) {
    if (target == 0) {
        res.push_back(curr);
        return;
    }

    for (int i = idx; i < candidates.size(); i++) {
        if (i > idx && candidates[i] == candidates[i - 1]) continue; 
        if (candidates[i] > target) break; 
        curr.push_back(candidates[i]);
        rec(res, candidates, target - candidates[i], curr, i + 1);
        curr.pop_back();
    }
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        sort(candidates.begin(),candidates.end());
        rec(res,candidates,target,{},0);
        return res;
    }
};