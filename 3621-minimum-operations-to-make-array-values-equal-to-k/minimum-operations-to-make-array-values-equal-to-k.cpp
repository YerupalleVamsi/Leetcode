class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if (*min_element(nums.begin(), nums.end()) < k) {
            return -1;
        }
        
        set<int> elements(nums.begin(), nums.end());
        
        if (elements.find(k) != elements.end()) {
            elements.erase(k);
        }
        
        return elements.size();
    }
};