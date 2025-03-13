class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        // Prefix array to store the effect of the range operations
        vector<int> prefix(n + 1, 0);

        // Apply the range operations using the prefix array technique
        for (auto& it : queries) {
            int l = it[0];
            int r = it[1];
            prefix[l] -= 1;        // Decrement the start of the range
            prefix[r + 1] += 1;    // Increment the position just after the end of the range
        }

        // Calculate the cumulative effect using the prefix sum
        for (int i = 1; i < n; i++) {
            prefix[i] += prefix[i - 1];
        }

        // Check if the final array becomes zero for all indices
        for (int i = 0; i < n; i++) {
            // If the modified value of nums[i] is greater than zero, return false
            if (prefix[i] + nums[i] > 0)
                return false;
        }

        // If all elements are zero, return true
        return true;
    }
};