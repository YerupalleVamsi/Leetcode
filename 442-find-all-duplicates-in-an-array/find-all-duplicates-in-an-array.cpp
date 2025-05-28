class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        if (nums.size() <= 1) {
            return res;
        }

        sort(nums.begin(), nums.end());

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                res.push_back(nums[i]);
            }
        }

        set<int> unique(res.begin(), res.end());
        return vector<int>(unique.begin(), unique.end());
    }
};
