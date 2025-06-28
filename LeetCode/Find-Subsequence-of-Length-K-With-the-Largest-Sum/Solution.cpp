class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> temp;
        for (int i = 0; i < nums.size(); i++) {
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end(), greater<>());
        temp.resize(k);
        sort(temp.begin(), temp.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });
        vector<int> res;
        for (auto& p : temp) {
            res.push_back(p.first);
        }

        return res;
    }
};
