
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0, xor2 = 0;

        for (int i = 0; i < n; ++i) {
            xor1 ^= nums[i];
        }

        for (int i = 1; i <= n; ++i) {
            xor2 ^= i;
        }
        int dup = -1;
        std::unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
            if (count[num] == 2) {
                dup = num;
                break;
            }
        }

        int missing = xor1 ^ xor2 ^ dup;

        return {dup, missing};
    }
};
