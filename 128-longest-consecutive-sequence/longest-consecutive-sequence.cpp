class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
        unordered_map<int, int> mp;
        int cnt = 0, maxCount = 0;
        for (int num : nums) {
            mp[num] = 0;
        }
        for (int num : nums) {
            if (mp.find(num) != mp.end()) {
                mp[num]++;
            }
        }
        for (auto& [key, value] : mp) {
            if (mp.find(key - 1) == mp.end()) {
                int currentNum = key;
                cnt = 0;
                while (mp.find(currentNum) != mp.end() && mp[currentNum] >0)               {
                    cnt++;
                    currentNum++;
                }

                maxCount = max(maxCount, cnt);
            }
        }

        return maxCount;
    }
};