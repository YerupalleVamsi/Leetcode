class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, count = 0;
        unordered_map<int, int> freq;

        for (r = 0; r < n; ++r) {
            if (freq[nums[r]] == 0) {
                k--; // unq char ochhindi mowa
            }
            freq[nums[r]]++;

            while (k < 0) {
                freq[nums[l]]--; // sliding window decrease the len of window so that k is not < 0..
                if (freq[nums[l]] == 0) {
                    k++; // freq 0 so we dont have that unq char now so k++
                }
                l++;
            }

            count += (r - l + 1); // imp step to calculate the number of subarrays 
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
