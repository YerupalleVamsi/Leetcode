// only recursion with out  for loop
// class Solution {
// public:
//  void rec(vector<vector<int>>& res, vector<int>& candidates, int target,
//           vector<int> curr, int idx, int currsum, bool prevTaken) {       
//      if (currsum == target) {
//         res.push_back(curr);
//        return;
//  }
//       if (currsum > target || idx >= candidates.size()) {
//           return;
//        }
//
//        // skip duplicate only if we did NOT take the previous one
//        if (idx > 0 && candidates[idx] == candidates[idx - 1] && !prevTaken) {
//            rec(res, candidates, target, curr, idx + 1, currsum, false);
//            return;
//        }
//      //take
//        curr.push_back(candidates[idx]);
//        rec(res, candidates, target, curr, idx + 1, currsum + candidates[idx], true);
//        curr.pop_back();
//
//        // not take
//        rec(res, candidates, target, curr, idx + 1, currsum, false);
//    }
//
//    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//        vector<vector<int>> res;
//        sort(candidates.begin(), candidates.end());
//        rec(res, candidates, target, {}, 0, 0, false);
//        return res;
//    }
//};

class Solution {
public:
    void rec(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>curr, int idx) {
    if (target == 0) {
        res.push_back(curr);
        return;
    }
    // using for loop
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