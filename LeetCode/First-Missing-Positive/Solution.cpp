class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        
        
        for (int i = 0; i < size; i++) {
            if (nums[i] <= 0) {
                nums[i] = size + 1;
            }
        }
        
    
        for (int i = 0; i < size; i++) {
            int value = abs(nums[i]);
            if (value <= size) {
                nums[value - 1] = -abs(nums[value - 1]);
            }
        }
        
        
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        
        return size + 1;
    }
};
