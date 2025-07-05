class Solution {
public:
    void rec(vector<vector<int>>& res, vector<int>& nums, int idx, vector<int> currset) {
        if (idx == nums.size()) {
            res.push_back(currset);
            return;
        }

        // Do not include current element
        rec(res, nums, idx + 1, currset);

        // Include current element
        currset.push_back(nums[idx]);
        rec(res, nums, idx + 1, currset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        rec(res, nums, 0, {});
        return res;
    }
};
